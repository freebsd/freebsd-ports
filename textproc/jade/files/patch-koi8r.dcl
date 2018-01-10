--- /dev/null	Sat Jul 31 17:25:08 2004
+++ pubtext/koi8r.dcl	Sat Jul 31 17:04:35 2004
@@ -0,0 +1,236 @@
+		     <!SGML "ISO 8879:1986 (ENR)"
+
+-- SGML Declaration that declares document charset to be the alphabet   --
+-- part of the koi8-r encoding.                                         --
+
+-- Derived from default declaration for James Clark's SP SGML parser.   --
+-- Only parts related to character sets was modified.  Tailor the rest  --
+-- of the defaults to suit your needs.                                  --
+
+-- Thanks to OmniMark for their excellent paper "Understanding The      --
+-- SGML Declaration" (http://www.omnimark.com/resources/white/dec/)     --
+-- [Copyright OmniMark Technologies Corporation, 1997. All rights       --
+-- reserved].  Few key paragraphs from this paper are quoted below to   --
+-- give you some idea of what is going on.                              --
+
+-- Many, many thanks to James Clark for his patience and kind help.     --
+
+
+
+-- The meanings of characters in an SGML document are defined using     --
+-- three types of character sets:                                       --
+
+-- 1. The "syntax-reference character set" is used to assign meanings   --
+--    to character numbers.                                             --
+
+-- 2. A correspondence is defined between characters in the             --
+--    syntax-reference character set and characters in a "base          --
+--    character set", which transfers the meanings of syntax-reference  --
+--    characters to corresponding base characters.                      --
+
+-- 3. A correspondence is then defined between characters in one or     --
+--    more base character sets and the "document character set".  One   --
+--    of the base character sets must have been defined by being        --
+--    associated with a syntax-reference character set in a previous    --
+--    step.                                                             --
+
+CHARSET
+
+-- The document character set is what defines what characters can be    --
+-- used in the markup and text of a document and defines what those     --
+-- characters mean.                                                     --
+
+        -- The document character set part of the SGML Declaration      --
+        -- selects one or more base character sets ...                  --
+
+        BASESET  "ISO Registration Number 176//CHARSET
+                  ISO/IEC 10646-1:1993 UCS-2
+                  with implementation level 3//ESC 2/5 2/15 4/5"
+
+
+        -- ... and defines the correspondences between characters in    --
+        -- the base character sets and the document character set.      --
+
+        DESCSET    0  9 UNUSED
+                   9  2      9
+                  11  2 UNUSED
+                  13  1     13
+                  14 18 UNUSED
+                  32 95     32
+                 127 36 UNUSED
+                 163  1   1105 -- CYRILLIC SMALL LETTER IO --
+                 164 15 UNUSED
+                 179  1   1025 -- CYRILLIC CAPITAL LETTER IO --
+                 180 11 UNUSED
+                 191  1    169 -- COPYRIGHT SIGN --
+                 192  1   1102 -- CYRILLIC SMALL LETTER YU --
+                 193  1   1072 -- CYRILLIC SMALL LETTER A --
+                 194  1   1073 -- CYRILLIC SMALL LETTER BE --
+                 195  1   1094 -- CYRILLIC SMALL LETTER TSE --
+                 196  1   1076 -- CYRILLIC SMALL LETTER DE --
+                 197  1   1077 -- CYRILLIC SMALL LETTER IE --
+                 198  1   1092 -- CYRILLIC SMALL LETTER EF --
+                 199  1   1075 -- CYRILLIC SMALL LETTER GHE --
+                 200  1   1093 -- CYRILLIC SMALL LETTER HA --
+                 201  1   1080 -- CYRILLIC SMALL LETTER I --
+                 202  1   1081 -- CYRILLIC SMALL LETTER SHORT I --
+                 203  1   1082 -- CYRILLIC SMALL LETTER KA --
+                 204  1   1083 -- CYRILLIC SMALL LETTER EL --
+                 205  1   1084 -- CYRILLIC SMALL LETTER EM --
+                 206  1   1085 -- CYRILLIC SMALL LETTER EN --
+                 207  1   1086 -- CYRILLIC SMALL LETTER O --
+                 208  1   1087 -- CYRILLIC SMALL LETTER PE --
+                 209  1   1103 -- CYRILLIC SMALL LETTER YA --
+                 210  1   1088 -- CYRILLIC SMALL LETTER ER --
+                 211  1   1089 -- CYRILLIC SMALL LETTER ES --
+                 212  1   1090 -- CYRILLIC SMALL LETTER TE --
+                 213  1   1091 -- CYRILLIC SMALL LETTER U --
+                 214  1   1078 -- CYRILLIC SMALL LETTER ZHE --
+                 215  1   1074 -- CYRILLIC SMALL LETTER VE --
+                 216  1   1100 -- CYRILLIC SMALL LETTER SOFT SIGN --
+                 217  1   1099 -- CYRILLIC SMALL LETTER YERU --
+                 218  1   1079 -- CYRILLIC SMALL LETTER ZE --
+                 219  1   1096 -- CYRILLIC SMALL LETTER SHA --
+                 220  1   1101 -- CYRILLIC SMALL LETTER E --
+                 222  1   1095 -- CYRILLIC SMALL LETTER CHE --
+                 221  1   1097 -- CYRILLIC SMALL LETTER SHCHA --
+                 223  1   1098 -- CYRILLIC SMALL LETTER HARD SIGN --
+                 224  1   1070 -- CYRILLIC CAPITAL LETTER YU --
+                 225  1   1040 -- CYRILLIC CAPITAL LETTER A --
+                 226  1   1041 -- CYRILLIC CAPITAL LETTER BE --
+                 227  1   1062 -- CYRILLIC CAPITAL LETTER TSE --
+                 228  1   1044 -- CYRILLIC CAPITAL LETTER DE --
+                 229  1   1045 -- CYRILLIC CAPITAL LETTER IE --
+                 230  1   1060 -- CYRILLIC CAPITAL LETTER EF --
+                 231  1   1043 -- CYRILLIC CAPITAL LETTER GHE --
+                 232  1   1061 -- CYRILLIC CAPITAL LETTER HA --
+                 233  1   1048 -- CYRILLIC CAPITAL LETTER I --
+                 234  1   1049 -- CYRILLIC CAPITAL LETTER SHORT I --
+                 235  1   1050 -- CYRILLIC CAPITAL LETTER KA --
+                 236  1   1051 -- CYRILLIC CAPITAL LETTER EL --
+                 237  1   1052 -- CYRILLIC CAPITAL LETTER EM --
+                 238  1   1053 -- CYRILLIC CAPITAL LETTER EN --
+                 239  1   1054 -- CYRILLIC CAPITAL LETTER O --
+                 240  1   1055 -- CYRILLIC CAPITAL LETTER PE --
+                 241  1   1071 -- CYRILLIC CAPITAL LETTER YA --
+                 242  1   1056 -- CYRILLIC CAPITAL LETTER ER --
+                 243  1   1057 -- CYRILLIC CAPITAL LETTER ES --
+                 244  1   1058 -- CYRILLIC CAPITAL LETTER TE --
+                 245  1   1059 -- CYRILLIC CAPITAL LETTER U --
+                 246  1   1046 -- CYRILLIC CAPITAL LETTER ZHE --
+                 247  1   1042 -- CYRILLIC CAPITAL LETTER VE --
+                 248  1   1068 -- CYRILLIC CAPITAL LETTER SOFT SIGN --
+                 249  1   1067 -- CYRILLIC CAPITAL LETTER YERU --
+                 250  1   1047 -- CYRILLIC CAPITAL LETTER ZE --
+                 251  1   1064 -- CYRILLIC CAPITAL LETTER SHA --
+                 252  1   1069 -- CYRILLIC CAPITAL LETTER E --
+                 253  1   1065 -- CYRILLIC CAPITAL LETTER SHCHA --
+                 254  1   1063 -- CYRILLIC CAPITAL LETTER CHE --
+                 255  1   1066 -- CYRILLIC CAPITAL LETTER HARD SIGN --
+
+CAPACITY
+        PUBLIC  "ISO 8879:1986//CAPACITY Reference//EN"
+
+SCOPE
+        DOCUMENT
+
+SYNTAX
+        SHUNCHAR CONTROLS
+
+        -- The Syntax-Reference Character Set is defined similarly to   --
+        -- the document character set.  It is, however, used            --
+        -- exclusively to define the concrete syntax.  The character    --
+        -- assignments within it are used only in the following         --
+        -- concrete syntax definitions.                                 --
+
+        -- The main function of the concrete syntax is to assign        --
+        -- meanings to characters: to make them name characters or      --
+        -- function characters, such as RE.  The meaning given in the   --
+        -- concrete syntax to each syntax-reference character is        --
+        -- assigned to the corresponding base character.  The document  --
+        -- character set then assigns these meanings to the characters  --
+        -- in the parsed document itself.                               --
+
+        BASESET  "ISO Registration Number 176//CHARSET
+                  ISO/IEC 10646-1:1993 UCS-2
+                  with implementation level 3//ESC 2/5 2/15 4/5"
+
+        DESCSET    0   9 UNUSED
+                   9   2      9
+                  11   2 UNUSED
+                  13   1     13
+                  14  18 UNUSED
+                  32  95     32
+                 127  42 UNUSED
+                 169   1    169         -- COPYRIGHT SIGN --
+                 170 855 UNUSED
+	        1025   1   1025         -- CYRILLIC CAPITAL LETTER IO --
+                1026  14 UNUSED
+                1040  64   1040         -- russian alphabet except io --
+                1104   1 UNUSED
+                1105   1   1105         -- CYRILLIC SMALL LETTER IO --
+
+        FUNCTION
+                RE              13      -- record end --
+                RS              10      -- record start --
+                SPACE           32      -- space --
+                TAB SEPCHAR      9      -- additional spec chars --
+
+        NAMING
+                -- Now declare that russian letters are valid chars to --
+                -- start names with and define case mapping as well.   --
+                -- Use TC for Extended Naming Rules (Annex J to 8879). --
+
+                LCNMSTRT 1072-1103 1105
+                UCNMSTRT 1040-1071 1025
+                LCNMCHAR  ".-"
+                UCNMCHAR  ".-"
+                NAMECASE  GENERAL YES
+                          ENTITY  NO
+
+        DELIM
+                GENERAL   SGMLREF
+                SHORTREF  SGMLREF
+
+        NAMES   SGMLREF
+
+        QUANTITY
+                SGMLREF
+                ATTCNT    99999999
+                ATTSPLEN  99999999
+                DTEMPLEN  24000
+                ENTLVL    99999999
+                GRPCNT    99999999
+                GRPGTCNT  99999999
+                GRPLVL    99999999
+                LITLEN    24000
+                NAMELEN   99999999
+                PILEN     24000
+                TAGLEN    99999999
+                TAGLVL    99999999
+
+-- End of SYNTAX --
+
+FEATURES -- feature usage declarations --
+
+        MINIMIZE
+                DATATAG  NO
+                OMITTAG  YES
+                RANK     YES
+                SHORTTAG YES
+
+        LINK
+                SIMPLE   YES 1000
+                IMPLICIT YES
+                EXPLICIT YES 1
+
+        OTHER
+                CONCUR  NO
+                SUBDOC  YES 99999999
+                FORMAL  YES
+
+-- End of FEATURES --
+
+APPINFO
+        NONE
+>
