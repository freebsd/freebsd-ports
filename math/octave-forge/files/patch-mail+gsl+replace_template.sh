--- main/gsl/replace_template.sh.org	Mon Nov 22 11:15:02 2004
+++ main/gsl/replace_template.sh	Mon Nov 22 11:15:11 2004
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-csplit -f tmp_gsl $1 /DEFUN/ /GSL_FUNC_DOCSTRING/ /./ > /dev/null
+gcsplit -f tmp_gsl $1 /DEFUN/ /GSL_FUNC_DOCSTRING/ /./ > /dev/null
 cat tmp_gsl01 | sed "s/GSL_OCTAVE_NAME/$octave_name/g"
 cat docstring.txt | sed 's/\\/\\\\/g' | sed 's/$/\\n\\/g' 
 cat tmp_gsl03 | sed "s/GSL_OCTAVE_NAME/$octave_name/g" | sed "s/GSL_FUNC_NAME/$funcname/g" 
