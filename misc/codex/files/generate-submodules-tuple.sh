#! /bin/sh

PATH=/bin:/usr/bin:${LOCALBASE:=/usr/local}/bin

GH_ACCOUNT=$1
GH_PROJECT=$2
GH_TAGNAME=$3

GITMODULES=$(fetch -q -o - "https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}/.gitmodules")

fetch -q -o - "https://api.github.com/repos/${GH_ACCOUNT}/${GH_PROJECT}/git/trees/${GH_TAGNAME}?recursive=1" | \
    jq -r --arg conf "${GITMODULES}" '
        .tree[] |
        select(.type == "commit") | .path as $path | .sha as $sha |
        ($conf | split("\n") | map(select(test("path|url"))) |
            . as $lines |
            reduce range(0, length) as $i (null;
            if (($lines[$i] | sub("^[ \t]*path[ \t]*=[ \t]*\"?"; "") | sub("\"?[ \t]*$"; "")) == $path) then
                $lines[$i+1] | sub("^[ \t]*url[ \t]*=[ \t]*"; "") | sub("[ \t]*$"; "")
            else
                .
            end
        )) as $url |
        ($url | sub("\\.git$"; "")) as $clean_url |
        "\t\t\($clean_url) \($sha) \($path)"
        ' | \
    awk '
    BEGIN { print "V8_SUBMODULES_TUPLE=	\\" }
    {
        printf("\t\t%s %s %s ", $1, $2, $3)
        gsub(/[^a-zA-Z0-9_]/, "__", $3)
        printf("%s-%s.tar.gz \\\n", $3, $2)
    }'
