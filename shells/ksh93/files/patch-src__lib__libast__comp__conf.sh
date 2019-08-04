--- files/patch-src_lib_libast_comp_conf.sh.orig	2019-08-04 16:51:09 UTC
+++ files/patch-src_lib_libast_comp_conf.sh
@@ -0,0 +1,1343 @@
+--- src/lib/libast/comp/conf.sh.orig	2019-04-16 20:04:19 UTC
++++ src/lib/libast/comp/conf.sh
+@@ -1,1340 +0,0 @@
+-#!/bin/sh
+-########################################################################
+-#                                                                      #
+-#               This software is part of the ast package               #
+-#          Copyright (c) 1985-2013 AT&T Intellectual Property          #
+-#                      and is licensed under the                       #
+-#                 Eclipse Public License, Version 1.0                  #
+-#                    by AT&T Intellectual Property                     #
+-#                                                                      #
+-#                A copy of the License is available at                 #
+-#          http://www.eclipse.org/org/documents/epl-v10.html           #
+-#         (with md5 checksum b35adb5213ca9657e911e9befb180842)         #
+-#                                                                      #
+-#              Information and Software Systems Research               #
+-#                            AT&T Research                             #
+-#                           Florham Park NJ                            #
+-#                                                                      #
+-#               Glenn Fowler <glenn.s.fowler@gmail.com>                #
+-#                    David Korn <dgkorn@gmail.com>                     #
+-#                     Phong Vo <phongvo@gmail.com>                     #
+-#                                                                      #
+-########################################################################
+-#
+-# @(#)conf.sh (AT&T Research) 2011-08-26
+-#
+-# This script generates these files from the table file:
+-#
+-# conflim.h  supplemental limits.h definitions
+-# conftab.h  readonly string table definitions
+-# conftab.c  readonly string table data
+-#
+-# You may think it should be simpler but you shall be confused anyway.
+-#
+-export LC_ALL=C
+-
+-command=`basename $0`
+-source_dir="$MESON_SOURCE_ROOT/src/lib/libast/comp"
+-target_dir="$MESON_BUILD_ROOT/src/lib/libast/comp"
+-table=$source_dir/conf.tab
+-test $# -gt 0 || { echo missing expected compiler args >&2; exit 1; }
+-cc=$*
+-
+-PATH="$MESON_SOURCE_ROOT/scripts:$PATH"
+-
+-# The use of `mktemp -dt` isn't ideal as it has slightly different meaning on BSD and GNU. But for
+-# our purposes that doesn't matter. It simply means the temp file name will contain the X's on a BSD
+-# system. See https://github.com/att/ast/issues/939
+-tmpdir=$(mktemp -dt ksh.XXXXXX)
+-tmp=$tmpdir/conf
+-cd $tmpdir || exit
+-trap "rm -rf $tmpdir" EXIT
+-
+-# We need to create the Meson build directory that will contain the
+-# dynamically generated source files.
+-test -d "$target_dir" || mkdir -p "$target_dir"
+-
+-# We don't bother doing this test before creating the temp dir because we
+-# don't expect this to ever fail unless the project source has been damaged.
+-if test ! -f $table
+-then
+-    echo "$command: cannot read: $table" >&2
+-    exit 1
+-fi
+-
+-# Setting the compiler's error-limit to zero (or a number much larger than the usual default of 20)
+-# is important to the proper functioning of the `defined()` function below. The default limit can,
+-# through pure chance, cause the inner loop of that function to terminate prematurely when it
+-# decides it isn't making forward progress in eliminating symbol errors. This also makes that
+-# process much more efficient. Unfortunately we can't just assume the compiler supports this so
+-# only use the flag if it does. Otherwise hope for the best with the default error limit.
+-cat > $tmp.c <<!
+-int main() { return 1; }
+-!
+-error_limit=''
+-if $cc -ferror-limit=0 $tmp.c
+-then
+-    error_limit="-ferror-limit=0"
+-fi
+-
+-append=0
+-extra=0
+-keep_call='*'
+-keep_name='*'
+-
+-# Note that header "config_ast.h" is created during the Meson feature detection phase. And this
+-# script runs after that has completed. That header contains things like the definition of
+-# `_ast_intmax_t` that this script depends upon.
+-head='
+-#include "config_ast.h"
+-
+-#include <stdint.h>
+-#include <stdbool.h>
+-#include <sys/types.h>
+-'
+-
+-tail='
+-#include <sys/param.h>
+-#include <sys/stat.h>
+-'
+-
+-headers=
+-ifs=${IFS}
+-tab='	'  # this should be the only place a literal tab appears in this script
+-nl='
+-'
+-sym=[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_]*
+-
+-# determine the intmax_t printf format
+-
+-cat > $tmp.c <<!
+-${head}
+-
+-int main() {
+-#if _ast_intmax_long
+-    return 1;
+-#else
+-    return 0;
+-#endif
+-}
+-!
+-
+-if $cc -o $tmp.exe $tmp.c && $tmp.exe
+-then
+-    LL_format='ll'
+-else
+-    LL_format='l'
+-fi
+-
+-# determine the intmax_t constant suffix
+-
+-cat > $tmp.c <<!
+-${head}
+-
+-int main() {
+-#if _ast_intmax_long
+-    return 1;
+-#else
+-    _ast_intmax_t           s = 0x7fffffffffffffffLL;
+-    unsigned _ast_intmax_t  u = 0xffffffffffffffffLL;
+-
+-    return 0;
+-#endif
+-}
+-!
+-
+-if $cc -o $tmp.exe $tmp.c
+-then
+-    if $tmp.exe
+-    then
+-        LL_suffix='LL'
+-    else
+-        LL_suffix='L'
+-    fi
+-else
+-    LL_suffix=''
+-fi
+-
+-# This value was dynamically determined by the legacy IFFE based version of this script. Since we
+-# can now safely assume every platform we run on supports this syntax (e.g., `1U`) just hardcode it
+-# rather than running a compiler test to see if it works.
+-U_suffix='U'
+-
+-# Set up the names and keys.
+-
+-keys=
+-standards=
+-
+-case $append$extra in
+-00)
+-    echo "$command: read $table" >&2
+-    exec < $table
+-    while :
+-    do
+-        IFS=""
+-        read line
+-        eof=$?
+-        IFS=$ifs
+-        case $eof in
+-        0)      ;;
+-        *)      break ;;
+-        esac
+-        case $line in
+-        ""|\#*) ;;
+-        *) set x $line
+-            shift; name=$1
+-            shift; standard=$1
+-            shift; call=$1
+-            shift; section=$1
+-            shift; flags=$1
+-            alternates=
+-            define=
+-            values=
+-            script=
+-            headers=
+-            while   :
+-            do      shift
+-                    case $# in
+-                    0)      break ;;
+-                    esac
+-                    case $1 in
+-                    ":")    shift
+-                            eval script='$'script_$1
+-                            break
+-                            ;;
+-                    *"{")   case $1 in
+-                            "sh{")  script="# $name" ;;
+-                            *)      script= ;;
+-                            esac
+-                            shift
+-                            args="$*"
+-                            IFS=""
+-                            while   read line
+-                            do      case $line in
+-                                    "}")    break ;;
+-                                    esac
+-                                    script="$script$nl$line"
+-                            done
+-                            IFS=$ifs
+-                            break
+-                            ;;
+-                    *.h)    # These conf.tab entries are now ignored.
+-                            # We no longer build or use iffe to detect whether
+-                            # a given header is available. Too, not doing this
+-                            # appears to have no material effect on the build.
+-                            ;;
+-                    *)      values="$values $1"
+-                            case $1 in
+-                            $sym)   echo "$1" >> $tmp.v ;;
+-                            esac
+-                            ;;
+-                    esac
+-            done
+-            case " $standards " in
+-            *" $standard "*)
+-                    ;;
+-            *)      standards="$standards $standard"
+-                    ;;
+-            esac
+-            case $name:$flags in
+-            *:*S*)  ;;
+-            VERSION)flags="${flags}S" ;;
+-            esac
+-            case $name in
+-            *VERSION*)key=${standard}${section} ;;
+-            *)        key= ;;
+-            esac
+-            case $key in
+-            ''|*_)  key=${key}${name} ;;
+-            *)      key=${key}_${name} ;;
+-            esac
+-            eval sys='$'CONF_call_${key}
+-            case $sys in
+-            ?*)     call=$sys ;;
+-            esac
+-            case $call in
+-            SI)     sys=CS ;;
+-            *)      sys=$call ;;
+-            esac
+-            key=${sys}_${key}
+-            keys="$keys$nl$key"
+-            eval CONF_name_${key}='$'name
+-            eval CONF_standard_${key}='$'standard
+-            eval CONF_call_${key}='$'call
+-            eval CONF_section_${key}='$'section
+-            eval CONF_flags_${key}='$'flags
+-            eval CONF_define_${key}='$'define
+-            eval CONF_values_${key}='$'values
+-            eval CONF_script_${key}='$'script
+-            eval CONF_args_${key}='$'args
+-            eval CONF_headers_${key}='$'headers
+-            eval CONF_keys_${name}=\"'$'CONF_keys_${name} '$'key\"
+-            ;;
+-        esac
+-    done
+-    ;;
+-esac
+-
+-# ====================
+-# Check for native getconf(1).
+-#
+-CONF_getconf=
+-CONF_getconf_a=
+-for d in /usr/bin /bin /usr/sbin /sbin
+-do      if      test -x $d/getconf
+-        then    case `$d/getconf --?-version 2>&1` in
+-                *"AT&T"*"Research"*)
+-                        : presumably an implementation also configured from conf.tab
+-                        ;;
+-                *)      CONF_getconf=$d/getconf
+-                        if      $CONF_getconf -a >/dev/null 2>&1
+-                        then    CONF_getconf_a=-a
+-                        fi
+-                        ;;
+-                esac
+-                break
+-        fi
+-done
+-export CONF_getconf CONF_getconf_a
+-
+-echo "$command: check ${CONF_getconf:+$CONF_getconf(1),}confstr(2),pathconf(2),sysconf(2),sysinfo(2) configuration names" >&2
+-
+-{
+-    echo "
+-${head}
+-#include <unistd.h>
+-
+-int i = 0;" > $tmp.c
+-    $cc -E $tmp.c
+-} |
+-sed -e '/^#[^0123456789]*1[ '"$tab"']*".*".*/!d' \
+-    -e 's/^#[^0123456789]*1[ '"$tab"']*"\(.*\)".*/\1/' |
+-sort -u > $tmp.f
+-
+-{
+-    sed -e 's/[^ABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789]/ /g' \
+-        -e 's/[ '"$tab"'][ '"$tab"']*/\n/g' \
+-        `cat $tmp.f` 2>/dev/null |
+-        egrep '^(SI|_(CS|PC|SC|SI))_.'
+-        case $CONF_getconf_a in
+-        ?*)     $CONF_getconf $CONF_getconf_a | sed 's,[=:    ].*,,'
+-                ;;
+-        *)      case $CONF_getconf in
+-                ?*)     for v in `strings $CONF_getconf | grep '^[ABCDEFGHIJKLMNOPQRSTUVWXYZ_][ABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789]*$'`
+-                        do      if      $CONF_getconf $v >/dev/null
+-                                then    echo $v
+-                                fi
+-                        done
+-                        ;;
+-                esac
+-                ;;
+-        esac 2>/dev/null
+-} |
+-egrep -v '^_[ABCDEFGHIJKLMNOPQRSTUVWXYZ]+_(COUNT|LAST|N|STR)$' |
+-sort -u > $tmp.g
+-{
+-        grep '^_' $tmp.g
+-        grep '^[^_]' $tmp.g
+-} > $tmp.t
+-mv $tmp.t $tmp.g
+-
+-HOST=`"$MESON_SOURCE_ROOT/bin/hosttype" | sed -e 's,[0123456789.].*,,' | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ`
+-case $HOST in
+-'')     HOST=SYSTEM ;;
+-esac
+-
+-exec < $tmp.g
+-while   read line
+-do      flags=F
+-        section=
+-        underscore=
+-        define=$line
+-        IFS=_
+-        set $line
+-        IFS=$ifs
+-        case $1 in
+-        '')     case $# in
+-                0)      continue ;;
+-                esac
+-                shift
+-                ;;
+-        esac
+-        case $1 in
+-        CS|PC|SC|SI)
+-                call=$1
+-                shift
+-                standard=$1
+-                ;;
+-        *)      flags=${flags}R
+-                standard=$1
+-                while   :
+-                do      case $# in
+-                        0)      continue 2 ;;
+-                        esac
+-                        shift
+-                        case $1 in
+-                        CS|PC|SC|SI)
+-                                call=$1
+-                                shift
+-                                break
+-                                ;;
+-                        O|o|OLD|old)
+-                                continue 2
+-                                ;;
+-                        esac
+-                        standard=${standard}_$1
+-                done
+-                ;;
+-        esac
+-        case $1 in
+-        SET)    continue ;;
+-        esac
+-        case $standard in
+-        _*)     standard=`echo $standard | sed 's,^_*,,'` ;;
+-        esac
+-        case " $standards " in
+-        *" $standard "*)
+-                ;;
+-        *)      case $standard in
+-                [0123456789]*)
+-                        section=$standard
+-                        standard=POSIX
+-                        ;;
+-                *[0123456789])
+-                        eval `echo $standard | sed 's,\(.*\)\([0123456789]*\),standard=\1 section=\2,'`
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case $flags in
+-        *R*)    case $call in
+-                SI)     ;;
+-                *)      underscore=U ;;
+-                esac
+-                ;;
+-        *)      case " $standards " in
+-                " C ")  shift
+-                        ;;
+-                *" $standard "*)
+-                        case $call in
+-                        SI)     ;;
+-                        *)      flags=${flags}P
+-                                underscore=U
+-                                ;;
+-                        esac
+-                        shift
+-                        ;;
+-                *)      standard=
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case $standard in
+-        '')     standard=$HOST
+-                case $call in
+-                SI)     ;;
+-                *)      underscore=U ;;
+-                esac
+-                case $call in
+-                CS|PC|SC)
+-                        case $define in
+-                        _${call}_*)
+-                                standard=POSIX
+-                                ;;
+-                        esac
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        part=$section
+-        case $section in
+-        '')     section=1
+-                case $standard in
+-                POSIX|XOPEN) part=$section ;;
+-                esac
+-                ;;
+-        esac
+-        name=
+-        while   :
+-        do      case $# in
+-                0)      break ;;
+-                esac
+-                case $name in
+-                '')     name=$1 ;;
+-                *)      name=${name}_$1 ;;
+-                esac
+-                shift
+-        done
+-        case $name in
+-        '')     ;;
+-        HOSTTYPE|LIBPATH|LIBPREFIX|LIBSUFFIX|PATH_ATTRIBUTES|PATH_RESOLVE|UNIVERSE)
+-                ;;
+-        *)      values=
+-                script=
+-                args=
+-                headers=
+-                case $name in
+-                V[123456789]_*|V[123456789][0123456789]_*)      underscore=VW ;;
+-                esac
+-                case $call in
+-                CS|SI)  key=CS ;;
+-                *)      key=$call ;;
+-                esac
+-                case $name in
+-                *VERSION*)key=${key}_${standard}${part} ;;
+-                esac
+-                key=${key}_${name}
+-                eval x='$'CONF_keys_$name
+-                case $x in
+-                '')     eval x='$'CONF_name_$key
+-                        case $x in
+-                        '')     case $call in
+-                                SI)     flags=O$flags ;;
+-                                esac
+-                                case $underscore in
+-                                ?*)     flags=${flags}${underscore} ;;
+-                                esac
+-                                old=QQ
+-                                case $name in
+-                                *VERSION*)old=${old}_${standard}${part} ;;
+-                                esac
+-                                old=${old}_${name}
+-                                eval x='$'CONF_name_$old
+-                                case $x in
+-                                ?*)     eval CONF_name_$old=
+-                                        eval flags='$'flags'$'CONF_flags_$old
+-                                        eval values='$'CONF_values_$old
+-                                        eval script='$'CONF_script_$old
+-                                        eval args='$'CONF_args_$old
+-                                        eval headers='$'CONF_headers_$old
+-                                        ;;
+-                                esac
+-                                keys="$keys$nl$key"
+-                                eval CONF_name_${key}='$'name
+-                                eval CONF_standard_${key}='$'standard
+-                                eval CONF_call_${key}='$'call
+-                                eval CONF_section_${key}='$'section
+-                                eval CONF_flags_${key}=d'$'flags
+-                                eval CONF_define_${key}='$'define
+-                                eval CONF_values_${key}='$'values
+-                                eval CONF_script_${key}='$'script
+-                                eval CONF_args_${key}='$'args
+-                                eval CONF_headers_${key}='$'headers
+-                                ;;
+-                        *)      eval x='$'CONF_define_$key
+-                                case $x in
+-                                ?*)     case $call in
+-                                        CS)     eval x='$'CONF_call_$key
+-                                                case $x in
+-                                                SI)     ;;
+-                                                *)      define= ;;
+-                                                esac
+-                                                ;;
+-                                        *)      define=
+-                                                ;;
+-                                        esac
+-                                        ;;
+-                                esac
+-                                case $define in
+-                                ?*)     eval CONF_define_${key}='$'define
+-                                        eval CONF_call_${key}='$'call
+-                                        eval x='$'CONF_call_${key}
+-                                        case $x in
+-                                        QQ)     ;;
+-                                        *)      case $flags in
+-                                                *R*)    flags=R ;;
+-                                                *)      flags= ;;
+-                                                esac
+-                                                ;;
+-                                        esac
+-                                        case $call in
+-                                        SI)     flags=O$flags ;;
+-                                        esac
+-                                        eval CONF_flags_${key}=d'$'flags'$'CONF_flags_${key}
+-                                        ;;
+-                                esac
+-                                old=QQ
+-                                case $name in
+-                                *VERSION*)old=${old}_${standard}${part} ;;
+-                                esac
+-                                old=${old}_${name}
+-                                eval CONF_name_$old=
+-                        esac
+-                        ;;
+-                *)      for key in $x
+-                        do      eval x='$'CONF_call_${key}
+-                                case $x in
+-                                XX)     eval CONF_call_${key}=QQ
+-                                        eval CONF_flags_${key}=S'$'CONF_flags_${key}
+-                                        ;;
+-                                esac
+-                        done
+-                esac
+-                ;;
+-        esac
+-done
+-
+-# sort keys by name
+-
+-keys=`for key in $keys
+-do      eval echo '$'CONF_name_$key '$'key
+-done | sort -u | sed 's,.* ,,'`
+-
+-# mark the dups CONF_PREFIXED
+-
+-prev_key=
+-prev_name=
+-for key in $keys
+-do      eval name=\"'$'CONF_name_$key\"
+-        case $name in
+-        '')     continue
+-                ;;
+-        $prev_name)
+-                eval p='$'CONF_flags_${prev_key}
+-                eval c='$'CONF_flags_${key}
+-                case $p:$c in
+-                *L*:*L*);;
+-                *L*:*)  c=L${c} ;;
+-                *:*L*)  p=L${p} ;;
+-                *)      p=P$p c=P$c ;;
+-                esac
+-                eval CONF_flags_${prev_key}=$p
+-                eval CONF_flags_${key}=$c
+-                ;;
+-        esac
+-        prev_name=$name
+-        prev_key=$key
+-done
+-
+-# collect all the macros/enums
+-
+-for key in $keys
+-do      eval name=\"'$'CONF_name_$key\"
+-        case $name in
+-        '')             continue ;;
+-        $keep_name)     ;;
+-        *)              continue ;;
+-        esac
+-        eval call=\"'$'CONF_call_$key\"
+-        case $call in
+-        $keep_call)     ;;
+-        *)              continue ;;
+-        esac
+-        eval standard=\"'$'CONF_standard_$key\"
+-        eval section=\"'$'CONF_section_$key\"
+-        eval flags=\"'$'CONF_flags_$key\"
+-        eval define=\"'$'CONF_define_$key\"
+-        eval values=\"'$'CONF_values_$key\"
+-        eval script=\"'$'CONF_script_$key\"
+-        eval args=\"'$'CONF_args_$key\"
+-        eval headers=\"'$'CONF_headers_$key\"
+-        conf_name=$name
+-        case $call in
+-        QQ)     call=XX
+-                for c in SC PC CS
+-                do      case $flags in
+-                        *S*)    case $section in
+-                                1)      eval x='$'CONF_call_${c}_${standard}_${name} ;;
+-                                *)      eval x='$'CONF_call_${c}_${standard}${section}_${name} ;;
+-                                esac
+-                                ;;
+-                        *)      eval x='$'CONF_call_${c}_${name}
+-                                ;;
+-                        esac
+-                        case $x in
+-                        ?*)     call=$x
+-                                break
+-                                ;;
+-                        esac
+-                done
+-                case $call in
+-                XX)     for c in SC PC CS
+-                        do      echo "_${c}_${name}"
+-                                case $flags in
+-                                *S*)    case $section in
+-                                        1)      echo "_${c}_${standard}_${name}" ;;
+-                                        *)      echo "_${c}_${standard}${section}_${name}" ;;
+-                                        esac
+-                                        ;;
+-                                esac
+-                        done
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case $call in
+-        CS|PC|SC|SI|XX)
+-                ;;
+-        *)      echo "$command: $name: $call: invalid call" >&2
+-                exit 1
+-                ;;
+-        esac
+-        case $flags in
+-        *[ABEGHIJQTYZabcefghijklmnopqrstuvwxyz_123456789]*)
+-                echo "$command: $name: $flags: invalid flag(s)" >&2
+-                exit 1
+-                ;;
+-        esac
+-        case $section in
+-        [01])   ;;
+-        *)      case $flags in
+-                *N*)    ;;
+-                *)      name=${section}_${name} ;;
+-                esac
+-                standard=${standard}${section}
+-                ;;
+-        esac
+-        case $call in
+-        XX)     ;;
+-        *)      case $flags in
+-                *d*)    conf_op=${define} ;;
+-                *O*)    conf_op=${call}_${name} ;;
+-                *R*)    conf_op=_${standard}_${call}_${name} ;;
+-                *S*)    conf_op=_${call}_${standard}_${name} ;;
+-                *)      conf_op=_${call}_${name} ;;
+-                esac
+-                echo "${conf_op}"
+-                ;;
+-        esac
+-        case $standard:$flags in
+-        C:*)    ;;
+-        *:*L*)  echo "${conf_name}"
+-                echo "_${standard}_${conf_name}"
+-                ;;
+-        *:*M*)  case $section in
+-                1)      echo "_${standard}_${conf_name}" ;;
+-                *)      echo "_${standard}${section}_${conf_name}" ;;
+-                esac
+-                ;;
+-        esac
+-done > $tmp.q
+-sort -u < $tmp.q > $tmp.t
+-mv $tmp.t $tmp.q
+-sort -u < $tmp.v > $tmp.t
+-mv $tmp.t $tmp.v
+-
+-# test all the macros in a few batches (some compilers have an error limit)
+-
+-defined() # list-file
+-{
+-        : > $tmp.p
+-        while   :
+-        do      {
+-                        cat <<!
+-${head}
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-#undef conf
+-unsigned int conf[] = {
+-!
+-                        sed 's/$/,/' $1
+-                        echo "};"
+-                } > $tmp.c
+-                if $cc $error_limit -c $tmp.c > $tmp.e 2>&1
+-                then
+-                    break  # no compiler error implies all the symbols are valid
+-                fi
+-                python.sh sort_symbols.py < $tmp.e > $tmp.n
+-                cmp -s $tmp.n $tmp.p && break
+-                fgrep -x -v -f $tmp.n $1 > $tmp.y
+-                mv $tmp.y $1
+-                mv $tmp.n $tmp.p
+-        done
+-        {
+-                cat <<!
+-${head}
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-#undef conf
+-!
+-                sed 's/.*/conf "&" = &/' $1
+-        } > $tmp.c
+-        $cc -E $error_limit $tmp.c 2>/dev/null |
+-        sed -e '/conf[ '"$tab"']*".*"[ '"$tab"']*=[ '"$tab"']*/!d' \
+-            -e '/[_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789][ '"$tab"']*(/!d' -e 's/.*"\(.*\)".*/\1/' > $tmp.n
+-        if      test -s $tmp.n
+-        then    fgrep -x -v -f $tmp.n $1 > $tmp.y
+-                mv $tmp.y $1
+-        fi
+-}
+-
+-echo "$command: check macros/enums as static initializers" >&2
+-
+-defined $tmp.q
+-defined $tmp.v
+-
+-# mark the constant macros/enums
+-
+-exec < $tmp.q
+-while   read line
+-do      eval CONF_const_${line}=1
+-done
+-
+-exec < $tmp.v
+-while   read line
+-do      eval CONF_const_${line}=1
+-done
+-
+-# mark the string literal values
+-
+-{
+-        cat <<!
+-${head}
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-#undef conf
+-!
+-        sed 's/.*/conf "&" = &/' $tmp.q
+-} > $tmp.c
+-$cc -E $tmp.c |
+-sed -e '/conf[ '"$tab"']*".*"[ '"$tab"']*=[ '"$tab"']*"/!d' -e 's/.*"\([^"]*\)".*/\1/' > $tmp.e
+-exec < $tmp.e
+-while   read line
+-do      eval CONF_string_${line}=1
+-done
+-
+-# Walk through the table.
+-
+-name_max=1
+-export tmp name standard call cc
+-
+-exec > $tmp.t
+-for key in $keys
+-do      eval name=\"'$'CONF_name_$key\"
+-        case $name in
+-        '')             continue ;;
+-        $keep_name)     ;;
+-        *)              continue ;;
+-        esac
+-        eval call=\"'$'CONF_call_$key\"
+-        case $call in
+-        $keep_call)     ;;
+-        *)              continue ;;
+-        esac
+-        eval standard=\"'$'CONF_standard_$key\"
+-        eval section=\"'$'CONF_section_$key\"
+-        eval flags=\"'$'CONF_flags_$key\"
+-        eval define=\"'$'CONF_define_$key\"
+-        eval values=\"'$'CONF_values_$key\"
+-        eval script=\"'$'CONF_script_$key\"
+-        eval args=\"'$'CONF_args_$key\"
+-        eval headers=\"'$'CONF_headers_$key\"
+-        conf_name=$name
+-        case $call in
+-        QQ)     call=XX
+-                for c in SC PC CS
+-                do      case $flags in
+-                        *S*)    case $section in
+-                                1)      eval x='$'CONF_call_${c}_${standard}_${name} ;;
+-                                *)      eval x='$'CONF_call_${c}_${standard}${section}_${name} ;;
+-                                esac
+-                                ;;
+-                        *)      eval x='$'CONF_call_${c}_${name}
+-                                ;;
+-                        esac
+-                        case $x in
+-                        ?*)     call=$x
+-                                break
+-                                ;;
+-                        esac
+-                done
+-                case $call in
+-                XX)     for c in SC PC CS
+-                        do      case $flags in
+-                                *S*)    case $section in
+-                                        1)      eval x='$'CONF_const__${c}_${standard}_${name} ;;
+-                                        *)      eval x='$'CONF_const__${c}_${standard}${section}_${name} ;;
+-                                        esac
+-                                        ;;
+-                                *)      eval x='$'CONF_const__${c}_${name}
+-                                        ;;
+-                                esac
+-                                case $x in
+-                                1)      call=$c
+-                                        break
+-                                        ;;
+-                                esac
+-                        done
+-                        ;;
+-                esac
+-                case $call in
+-                XX)     case $standard in
+-                        C)      standard=POSIX ;;
+-                        esac
+-                        case $flags in
+-                        *L*)    flags=lFU ;;
+-                        *)      flags=FU ;;
+-                        esac
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case " $standards " in
+-        *" $standard "*)
+-                ;;
+-        *)      standards="$standards $standard"
+-                ;;
+-        esac
+-        conf_standard=CONF_${standard}
+-        case $call in
+-        CS)     conf_call=CONF_confstr
+-                ;;
+-        PC)     conf_call=CONF_pathconf
+-                ;;
+-        SC)     conf_call=CONF_sysconf
+-                ;;
+-        SI)     conf_call=CONF_sysinfo
+-                ;;
+-        XX)     conf_call=CONF_nop
+-                ;;
+-        esac
+-        conf_op=-1
+-        for s in _${call}_${standard}${section}_${name} _${call}_${standard}_${name} _${call}_${section}_${name} _${call}_${name} ${call}_${name}
+-        do      eval x='$'CONF_const_${s}
+-                case $x in
+-                1)      conf_op=${s}
+-                        break
+-                        ;;
+-                esac
+-        done
+-        conf_section=$section
+-        conf_flags=0
+-        case $flags in
+-        *C*)    conf_flags="${conf_flags}|CONF_DEFER_CALL" ;;
+-        esac
+-        case $flags in
+-        *D*)    conf_flags="${conf_flags}|CONF_DEFER_MM" ;;
+-        esac
+-        case $flags in
+-        *F*)    conf_flags="${conf_flags}|CONF_FEATURE" ;;
+-        esac
+-        case $flags in
+-        *L*)    conf_flags="${conf_flags}|CONF_LIMIT" ;;
+-        esac
+-        case $flags in
+-        *M*)    conf_flags="${conf_flags}|CONF_MINMAX" ;;
+-        esac
+-        case $flags in
+-        *N*)    conf_flags="${conf_flags}|CONF_NOSECTION" ;;
+-        esac
+-        case $flags in
+-        *P*)    conf_flags="${conf_flags}|CONF_PREFIXED" ;;
+-        esac
+-        case $flags in
+-        *S*)    conf_flags="${conf_flags}|CONF_STANDARD" ;;
+-        esac
+-        case $flags in
+-        *U*)    conf_flags="${conf_flags}|CONF_UNDERSCORE" ;;
+-        esac
+-        case $flags in
+-        *V*)    conf_flags="${conf_flags}|CONF_NOUNDERSCORE" ;;
+-        esac
+-        case $flags in
+-        *W*)    conf_flags="${conf_flags}|CONF_PREFIX_ONLY" ;;
+-        esac
+-        case $call in
+-        CS|SI)  conf_flags="${conf_flags}|CONF_STRING"
+-                string=1
+-                ;;
+-        *)      eval string='$'CONF_string_${key}
+-                ;;
+-        esac
+-        conf_limit=0
+-        case $flags in
+-        *[Ll]*) d=
+-                case ${conf_name} in
+-                LONG_MAX|SSIZE_MAX)
+-                        x=
+-                        ;;
+-                *)      eval x='$'CONF_const_${conf_name}
+-                        ;;
+-                esac
+-                case $x in
+-                '')     for s in ${values}
+-                        do      case $s in
+-                                $sym)   eval x='$'CONF_const_${s}
+-                                        case $x in
+-                                        1)      eval a='$'CONF_const_${standard}_${s}
+-                                                case $a in
+-                                                $x)     x= ;;
+-                                                *)      x=$s ;;
+-                                                esac
+-                                                break
+-                                                ;;
+-                                        esac
+-                                        ;;
+-                                [0123456789]*|[-+][0123456789]*)
+-                                        d=$s
+-                                        break
+-                                        ;;
+-                                esac
+-                        done
+-                        case ${x:+1}:$flags:$conf_op in
+-                        :*:-1|:*X*:*)
+-                                echo "$command: probe for ${conf_name} <limits.h> value" >&2
+-                                x=
+-                                case $CONF_getconf in
+-                                ?*)     if      $CONF_getconf $conf_name > $tmp.x 2>/dev/null
+-                                        then    x=`cat $tmp.x`
+-                                                case $x in
+-                                                undefined)      x= ;;
+-                                                esac
+-                                        fi
+-                                        ;;
+-                                esac
+-                                case ${x:+1} in
+-                                '')     case $script in
+-                                        '#'*)   echo "$script" > $tmp.sh
+-                                                chmod +x $tmp.sh
+-                                                x=`$tmp.sh 2>/dev/null`
+-                                                ;;
+-                                        '')     case $conf_name in
+-                                                SIZE_*|U*|*_MAX)
+-                                                        f="%${LL_format}u"
+-                                                        t="unsigned _ast_intmax_t"
+-                                                        ;;
+-                                                *)      f="%${LL_format}d"
+-                                                        t="_ast_intmax_t"
+-                                                        ;;
+-                                                esac
+-                                                cat > $tmp.c <<!
+-${head}
+-#include <stdio.h>
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-int
+-main()
+-{
+-        printf("$f\n", ($t)$conf_name);
+-        return 0;
+-}
+-!
+-                                                ;;
+-                                        *)      cat > $tmp.c <<!
+-${head}
+-#include <stdio.h>
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-${script}
+-!
+-                                                ;;
+-                                        esac
+-                                        case $args in
+-                                        '')     set "" ;;
+-                                        *)      eval set '""' '"'$args'"'; shift ;;
+-                                        esac
+-                                        for a
+-                                        do      case $script in
+-                                                '#'*)   $tmp.sh $a > $tmp.x
+-                                                        x=$?
+-                                                        ;;
+-                                                *)      $cc $a -o $tmp.exe $tmp.c && $tmp.exe > $tmp.x
+-                                                        x=$?
+-                                                        ;;
+-                                                esac
+-                                                case $x in
+-                                                0)      x=`cat $tmp.x`
+-                                                        case $x in
+-                                                        "-")    x=$a ;;
+-                                                        esac
+-                                                        break
+-                                                        ;;
+-                                                *)      x=
+-                                                        ;;
+-                                                esac
+-                                        done
+-                                        ;;
+-                                esac
+-                                case $x in
+-                                '')     x=$d ;;
+-                                esac
+-                                ;;
+-                        esac
+-                        case ${x:+1}:$flags:$conf_op in
+-                        1:*:-1|1:*X*:*)
+-                                conf_limit=$x
+-                                case $flags in
+-                                *L*)    ;;
+-                                *)      conf_flags="${conf_flags}|CONF_LIMIT" ;;
+-                                esac
+-                                conf_flags="${conf_flags}|CONF_LIMIT_DEF"
+-                        esac
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case $section in
+-        [01])   ;;
+-        *)      case $flags in
+-                *N*)    ;;
+-                *)      name=${section}_${name} ;;
+-                esac
+-                standard=${standard}${section}
+-                ;;
+-        esac
+-        conf_minmax=0
+-        case $call:$standard:$flags in
+-        *:C:*M*)for s in _${standard}_${conf_name} ${values}
+-                do      case $s in
+-                        $sym)   ;;
+-                        *)      conf_minmax=$s
+-                                conf_flags="${conf_flags}|CONF_MINMAX_DEF"
+-                                break
+-                                ;;
+-                        esac
+-                done
+-                ;;
+-        *:C:*)  ;;
+-        [CPSX][CSX]:*:*[FM]*)
+-                x=
+-                for s in _${standard}_${conf_name} ${values}
+-                do      case $s in
+-                        $sym)   eval x='$'CONF_const_${s} ;;
+-                        *)      x=1 ;;
+-                        esac
+-                        case $x in
+-                        1)      conf_minmax=$s
+-                                case $flags in
+-                                *M*)    conf_flags="${conf_flags}|CONF_MINMAX_DEF" ;;
+-                                esac
+-                                case $conf_minmax in
+-                                [-+0123456789]*)        x= ;;
+-                                esac
+-                                break
+-                                ;;
+-                        esac
+-                done
+-                case ${x:+1}:${script:+1} in
+-                :1)
+-                        echo "$command: probe for _${standard}_${conf_name} minmax value" >&2
+-                        case $CONF_getconf in
+-                        ?*)     if      $CONF_getconf _${standard}_${conf_name} > $tmp.x
+-                                then    x=`cat $tmp.x`
+-                                        case $x in
+-                                        undefined)      x= ;;
+-                                        esac
+-                                fi
+-                                ;;
+-                        esac
+-                        case $x in
+-                        '')     case $script in
+-                                '#'*)   echo "$script" > $tmp.sh
+-                                        chmod +x $tmp.sh
+-                                        x=`$tmp.sh`
+-                                        ;;
+-                                *)      cat > $tmp.c <<!
+-${head}
+-#include <sys/types.h>
+-#include <limits.h>
+-#include <unistd.h>
+-${headers}
+-${tail}
+-${script}
+-!
+-                                        ;;
+-                                esac
+-                                case $args in
+-                                '')     set "" ;;
+-                                *)      eval set '""' "$args"; shift ;;
+-                                esac
+-                                for a
+-                                do      case $script in
+-                                        '#'*)   $tmp.sh $a > $tmp.x
+-                                                x=$?
+-                                                ;;
+-                                        *)      $cc $a -o $tmp.exe $tmp.c && $tmp.exe > $tmp.x
+-                                                x=$?
+-                                                ;;
+-                                        esac
+-                                        case $x in
+-                                        0)      x=`cat $tmp.x`
+-                                                case $x in
+-                                                "-")    x=$a ;;
+-                                                esac
+-                                                break
+-                                                ;;
+-                                        *)      x=
+-                                                ;;
+-                                        esac
+-                                done
+-                                ;;
+-                        esac
+-                        case $x in
+-                        ?*)     conf_minmax=$x
+-                                case $flags in
+-                                *M*)    case "|$conf_flags|" in
+-                                        *'|CONF_MINMAX_DEF|'*)
+-                                                ;;
+-                                        *)      conf_flags="${conf_flags}|CONF_MINMAX_DEF"
+-                                                ;;
+-                                        esac
+-                                        ;;
+-                                esac
+-                                ;;
+-                        esac
+-                        ;;
+-                esac
+-                ;;
+-        esac
+-        case $string in
+-        1)      conf_limit="{ 0, $conf_limit }" conf_minmax="{ 0, $conf_minmax }"
+-                ;;
+-        *)      case $conf_limit in
+-                0[xX]*|-*|+*|[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_]*)
+-                        ;;
+-                *[!0123456789abcdefABCDEF]*)
+-                        conf_limit=0
+-                        ;;
+-                *[!0123456789]*)
+-                        conf_limit=0x$conf_limit
+-                        ;;
+-                esac
+-                case $conf_minmax in
+-                0[xX]*|-*|+*|[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_]*)
+-                        ;;
+-                *[!0123456789abcdefABCDEF]*)
+-                        conf_minmax=0
+-                        ;;
+-                *[!0123456789]*)
+-                        conf_minmax=0x$conf_minmax
+-                        ;;
+-                esac
+-                case $conf_limit in
+-                ?*[-+]*|*['()']*)
+-                        ;;
+-                *[lLuU])
+-                        case $LL_suffix in
+-                        ??)     case $conf_limit in
+-                                *[!lL][lL]|*[!lL][lL][uU])
+-                                        conf_limit=${conf_limit}L
+-                                        ;;
+-                                esac
+-                                ;;
+-                        esac
+-                        ;;
+-                -*[2468])
+-                        eval `echo '' $conf_limit | sed 's/ *\(.*\)\(.\) */p=\1 s=\2/'`
+-                        s=`expr $s - 1`
+-                        conf_limit=${p}${s}${LL_suffix}-1${LL_suffix}
+-                        ;;
+-                0[xX]*[abcdefABCDEF])
+-                        conf_limit=${conf_limit}${LL_suffix}
+-                        ;;
+-                -*[0123456789])
+-                        conf_limit=${conf_limit}${LL_suffix}
+-                        ;;
+-                *[0123456789])
+-                        conf_limit=${conf_limit}${U_suffix}${LL_suffix}
+-                        ;;
+-                esac
+-                case $conf_minmax in
+-                ?*[-+]*|*['()']*)
+-                        ;;
+-                *[lLuU])
+-                        case $LL_suffix in
+-                        ??)     case $conf_minmax in
+-                                *[!lL][lL]|*[!lL][lL][uU])
+-                                        conf_minmax=${conf_minmax}L
+-                                        ;;
+-                                esac
+-                                ;;
+-                        esac
+-                        ;;
+-                -*[2468])
+-                        eval `echo '' $conf_minmax | sed 's/ *\(.*\)\(.\) */p=\1 s=\2/'`
+-                        s=`expr $s - 1`
+-                        conf_minmax=${p}${s}${LL_suffix}-1${LL_suffix}
+-                        ;;
+-                0[xX]*[abcdefABCDEF])
+-                        conf_minmax=${conf_minmax}${LL_suffix}
+-                        ;;
+-                -*[0123456789])
+-                        conf_minmax=${conf_minmax}${LL_suffix}
+-                        ;;
+-                *[0123456789])
+-                        conf_minmax=${conf_minmax}${U_suffix}${LL_suffix}
+-                        ;;
+-                esac
+-                conf_limit="{ $conf_limit, 0 }" conf_minmax="{ $conf_minmax, 0 }"
+-                ;;
+-        esac
+-
+-        case $conf_flags in
+-        '0|'*)  conf_flags=`echo "$conf_flags" | sed 's/^0.//'`
+-                ;;
+-        esac
+-
+-        echo "{ \"$conf_name\", $conf_limit, $conf_minmax, $conf_flags, $conf_standard, $conf_section, $conf_call, $conf_op },"
+-        len=`echo ${conf_name} | wc -c`
+-        if      expr \( $len - 1 \) \>= ${name_max} >/dev/null
+-        then    name_max=$len
+-        fi
+-done
+-
+-# ====================
+-# Create the conftab.h header file.
+-#
+-echo "$command: generate conftab.h string table header" >&2
+-
+-name_max=`expr \( $name_max + 3 \) / 4 \* 4`
+-
+-conf_standards=
+-index=0
+-for standard in $standards
+-do
+-    standard="#define CONF_${standard} ${index}"
+-    conf_standards="$conf_standards$nl$standard"
+-    index=`expr $index + 1`
+-done
+-conf_standards="$conf_standards$nl#define CONF_call ${index}"
+-
+-getconf=
+-case $CONF_getconf in
+-?*) getconf="$getconf$nl#define _pth_getconf \"$CONF_getconf\""
+-    case $CONF_getconf_a in
+-    ?*) getconf="$getconf$nl#define _pth_getconf_a \"$CONF_getconf_a\"" ;;
+-    esac
+-    ;;
+-esac
+-
+-python.sh fill_template.py < ${source_dir}/conftab.h.in > ${target_dir}/conftab.h \
+-    conf_standards "$conf_standards" \
+-    getconf "$getconf" \
+-    name_max "$name_max"
+-test $? -eq 0 || { rm ${target_dir}/conftab.*; exit 1; }
+-
+-# ====================
+-# Create the conftab.c source file.
+-#
+-echo "$command: generate conftab.c string table" >&2
+-
+-prefix_standards=
+-for standard in $standards
+-do
+-        len=`echo ${standard} | wc -c`; len=`expr $len - 1`
+-        entry="    { \"${standard}\", ${len}, CONF_${standard}, -1 },"
+-        prefix_standards="$prefix_standards$nl$entry"
+-done
+-
+-getconf=`cat $tmp.t`
+-
+-python.sh fill_template.py < ${source_dir}/conftab.c.in > ${target_dir}/conftab.c \
+-    getconf "$getconf" \
+-    headers "$headers" \
+-    prefix_standards "$prefix_standards"
+-test $? -eq 0 || { rm ${target_dir}/conftab.*; exit 1; }
