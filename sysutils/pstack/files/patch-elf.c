--- elf.c.orig	2013-01-14 19:40:18 UTC
+++ elf.c
@@ -196,7 +196,7 @@ elfFindSymbolByAddress(struct ElfObject *obj, Elf_Addr
 		    symSection->sh_offset + symSection->sh_size);
 
 		for (; sym < endSym; sym++) {
-			if ((type == STT_NOTYPE ||
+			if ((ELF_ST_TYPE(sym->st_info) == STT_NOTYPE ||
 			    ELF_ST_TYPE(sym->st_info) == type) &&
 			    sym->st_value <= addr &&
 			    (shdrs[sym->st_shndx]->sh_flags & SHF_ALLOC)) {
