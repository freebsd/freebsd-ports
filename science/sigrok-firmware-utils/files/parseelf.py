#!/usr/bin/env python3
##
## This file is part of the sigrok-util project.
##
## Copyright (C) 2013 Marcus Comstedt <marcus@mc.pp.se>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, see <http://www.gnu.org/licenses/>.
##

import struct

class elf:

    def read_struct(this, struct_fmt, struct_fields):
        fmt = this.elf_endianprefix+str.translate(struct_fmt, this.elf_format);
        fields = struct.unpack(fmt, this.file.read(struct.calcsize(fmt)))
        return dict(zip(struct_fields, fields))

    def read_ehdr(this):
        return this.read_struct('16sHHWNNNWHHHHHH',
                                ('e_ident', 'e_type', 'e_machine', 'e_version',
                                 'e_entry', 'e_phoff', 'e_shoff', 'e_flags',
                                 'e_ehsize', 'e_phentsize', 'e_phnum',
                                 'e_shentsize', 'e_shnum', 'e_shstrndx'))

    def read_shdr(this):
        return this.read_struct('WWNNNNWWNN',
                                ('sh_name', 'sh_type', 'sh_flags', 'sh_addr',
                                 'sh_offset', 'sh_size', 'sh_link', 'sh_info',
                                 'sh_addralign', 'sh_entsize'))

    def read_section(this, shdr):
        this.file.seek(shdr['sh_offset'])
        return this.file.read(shdr['sh_size'])

    def get_name(this, name, strtab=None):
        strtab = strtab or this.strtab
        nul = strtab.find(b'\0', name)
        if nul < 0:
            return bytes.decode(strtab[name:])
        else:
            return bytes.decode(strtab[name:nul])

    def find_section(this, name):
        for section in this.shdrs:
            if this.get_name(section['sh_name']) == name:
                return section
        raise KeyError(name)

    def parse_symbol(this):
        if this.elf_wordsize == 64:
            return this.read_struct('WBBHNX',
                                    ('st_name', 'st_info', 'st_other',
                                     'st_shndx', 'st_value', 'st_size'))
        else:
            return this.read_struct('WNWBBH',
                                    ('st_name', 'st_value', 'st_size',
                                     'st_info', 'st_other', 'st_shndx'))

    def parse_rela(this):
        return this.read_struct('NNn', ('r_offset', 'r_info', 'r_addend'))

    def parse_rel(this):
        return this.read_struct('NN', ('r_offset', 'r_info'))

    def fixup_reloc(this, reloc):
        if not 'r_addend' in reloc:
            reloc['r_addend'] = 0
        if this.elf_wordsize == 64:
            reloc['r_sym'] = reloc['r_info'] >> 32
            reloc['r_type'] = reloc['r_info'] & 0xffffffff
        else:
            reloc['r_sym'] = reloc['r_info'] >> 8
            reloc['r_type'] = reloc['r_info'] & 0xff
        return reloc

    def parse_symbols(this, symsecname, strsecname):
        try:
            symsechdr = this.find_section(symsecname)
            strsechdr = this.find_section(strsecname)
        except KeyError:
            return {}
        strsec = this.read_section(strsechdr)
        this.file.seek(symsechdr['sh_offset'])
        syms = [dict(this.parse_symbol(),number=i) for i in
                range(0, symsechdr['sh_size'] // symsechdr['sh_entsize'])]
        return {this.get_name(sym['st_name'], strsec): sym for sym in syms}

    def parse_relocs(this, section):
        this.file.seek(section['sh_offset'])
        if section['sh_type'] == 4:
            relocs = [this.fixup_reloc(this.parse_rela()) for i in
                      range(0, section['sh_size'] // section['sh_entsize'])]
        else:
            relocs = [this.fixup_reloc(this.parse_rel()) for i in
                      range(0, section['sh_size'] // section['sh_entsize'])]
        return relocs

    def address_to_offset(this, addr):
        for section in this.shdrs:
            if (section['sh_addr'] <= addr and
                section['sh_addr']+section['sh_size'] > addr):
                return section['sh_offset']+(addr-section['sh_addr'])
        raise IndexError('address out of range')

    def load_symbol(this, sym):
        this.file.seek(this.address_to_offset(sym['st_value']))
        return this.file.read(sym['st_size'])

    def __init__(this, filename):
        this.file = open(filename, 'rb')
        magic = this.file.read(16)

        if magic[:4] != b'\x7fELF':
            raise Exception("ELF signature not found")

        if magic[4] == 1:
            this.elf_wordsize = 32
            nativeint = 'Ii'
        elif magic[4] == 2:
            this.elf_wordsize = 64
            nativeint = 'Qq'
        else:
            raise Exception("Invalid ELF file class")

        if magic[5] == 1:
            this.elf_endianprefix = '<'
        elif magic[5] == 2:
            this.elf_endianprefix = '>'
        else:
            raise Exception("Invalid ELF data encoding")

        this.elf_format = str.maketrans('HWwXxNn', 'HIiQq'+nativeint)

        this.file.seek(0)
        this.ehdr = this.read_ehdr()
        this.file.seek(this.ehdr['e_shoff'])
        this.shdrs = [this.read_shdr() for i in range(this.ehdr['e_shnum'])]

        this.strtab = this.read_section(this.shdrs[this.ehdr['e_shstrndx']])

        this.symtab = this.parse_symbols('.symtab', '.strtab')
        this.dynsym = this.parse_symbols('.dynsym', '.dynstr')

        this.relocs = {}
        for section in this.shdrs:
            if section['sh_type'] == 4 or section['sh_type'] == 9:
                rels = {}
                symsec = this.shdrs[section['sh_link']]
                if this.get_name(symsec['sh_name']) == '.symtab':
                    rels['symbols'] = this.symtab
                elif this.get_name(symsec['sh_name']) == '.dynsym':
                    rels['symbols'] = this.dynsym
                rels['relocs'] = this.parse_relocs(section)
                this.relocs[this.get_name(section['sh_name'])] = rels

    def __del__(this):
        try:
            this.file.close()
        except AttributeError:
            pass
