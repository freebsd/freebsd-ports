#!/usr/bin/awk -f

  BEGIN {
    XMLFILE=ARGV[2]
    delete ARGV[2]
    while (getline < XMLFILE) {
      if (/<\/vuxml>/)
        break
      print
    }
    XML=$0
    FS="|"
  }

  /^(#|$)/ { next }

  {
    if (PKG[$4])
      PKG[$4]=PKG[$4] FS $1
    else
      PKG[$4]=$1
    gsub(/</, "&lt;")
    gsub(/>/, "&gt;")
    gsub(/&/, "&amp;")
    URL[$4]=$2
    TOPIC[$4]=$3
  }

  END {
    OPN["<"]="lt"
    OPN["<="]="le"
    OPN["="]="eq"
    OPN[">="]="ge"
    OPN[">"]="gt"

    for (UUID in PKG) {
      print "  <vuln vid=\"" UUID "\">"
      print "    <topic>" TOPIC[UUID] "</topic>"

      print "    <affects>"
      split(PKG[UUID], APKG)
      for (TPKG in APKG) {
        VERS=APKG[TPKG]
        print "      <package>"
        if (match(VERS, /(<|>)=?|=/) > 0) {
          print "        <name>" substr(VERS, 1, RSTART-1) "</name>"
          printf "        <range>"
          do {
            OP=substr(VERS, RSTART, RLENGTH)
            LEN=length(VERS)
            VERS=substr(VERS, RSTART+RLENGTH, LEN+1-RSTART-RLENGTH)
            NEXTRANGE=match(VERS, /(<|>)=?|=/)
            if (NEXTRANGE > 0)
               printf "<%s>%s</%s>", OPN[OP], substr(VERS, 1, RSTART-1), OPN[OP]
            else
               printf "<%s>%s</%s>", OPN[OP], VERS, OPN[OP]
          } while (NEXTRANGE > 0)
          printf "</range>\n"
        }
        else {
          print "        <name>" VERS "</name>"
        }
        print "      </package>"
      }
      print "    </affects>"

      print "    <description>"
      print "      <body xmlns=\"http://www.w3.org/1999/xhtml\">"
      print "        <p>Please <a href=\"mailto:security@FreeBSD.org?subject=vid%20" UUID "\">contact"
      print "           the FreeBSD Security Team</a> for more information.</p>"
      print "      </body>"
      print "    </description>"
      print "    <references>"

      split(URL[UUID], URLS, / /)
      for (U in URLS) {
        if (!URLS[U])
          continue
        print "      <url>" URLS[U] "</url>"
      }

      print "    </references>"
      print "    <dates>"
      print "      <discovery>2000-00-00</discovery>"
      print "      <entry>2000-00-00</entry>"
      print "    </dates>"
      print "  </vuln>"
      print ""
    }
    print XML
    while (getline < XMLFILE) {
      print
    }
    close(XMLFILE)
  }
