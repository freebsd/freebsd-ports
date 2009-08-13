--- updateminiupnpcstrings.sh~
+++ updateminiupnpcstrings.sh
@@ -27,7 +27,7 @@ fi
 
 echo "Detected OS [$OS_NAME] version [$OS_VERSION]"
 
-EXPR="s/OS_STRING\s\".*\"/OS_STRING \"${OS_NAME}\/${OS_VERSION}\"/"
+EXPR="/OS_STRING/s|\".*\"|\"${OS_NAME}/${OS_VERSION}\"|"
 #echo $EXPR
 echo "Backuping $FILE to $FILE.bak."
 cp $FILE $FILE.bak
