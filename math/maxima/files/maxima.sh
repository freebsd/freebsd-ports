#!/bin/sh
MAXIMA_CORE="@MAXIMAPREFIX@src/maxima_core"
LISP="@LISPPREFIX@lisp"

${LISP} -core ${MAXIMA_CORE} -eval "(maxima::macsyma-top-level)"
