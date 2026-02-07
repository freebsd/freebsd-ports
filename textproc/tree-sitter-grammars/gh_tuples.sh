#!/bin/sh

# pkg install textproc/tomlq

vers="v0.4.2+1f9f9dd"

# https://github.com/lapce/tree-sitter-grammars/blob/v0.4.2%2B1f9f9dd/src/main.rs#L92

helix_rev=$(fetch -q -o - "https://raw.githubusercontent.com/lapce/tree-sitter-grammars/refs/tags/${vers}/src/main.rs" | grep -A1 "https://github.com/helix-editor/helix"  | tail -n 1 | sed -e 's# ##g' -e 's#"##g' -e 's#,##')

echo "https://raw.githubusercontent.com/helix-editor/helix/${helix_rev}/languages.toml"
exit
fetch -q https://raw.githubusercontent.com/helix-editor/helix/${helix_rev}/languages.toml

len=$(tomlq '.grammar | length' languages.toml)
len=$(expr ${len} - 1)

for i in $(seq 0 ${len})
do
	# git source and git rev
	name=$(tomlq ".grammar[${i}].name" languages.toml | sed 's#"##g')
	src=$(tomlq ".grammar[${i}].source.git" languages.toml | sed 's#"##g')
	rev=$(tomlq ".grammar[${i}].source.rev" languages.toml | sed 's#"##g')
	subpath=$(tomlq ".grammar[${i}].source.subpath" languages.toml | sed 's#"##g')

	echo ${src} | grep -q github.com
	if [ $? -ne 0 ]; then
#		echo "XXX $src, $rev not a github repo"
		continue
	fi

	src_a=$(echo ${src} | awk -F '/' '{print $4}')
	src_b=$(echo ${src} | awk -F '/' '{print $5}')

	echo "${src_a}:${src_b}:${rev}:ts${i}/grammars/tree-sitter-${name} \\"
done
