# $FreeBSD$

all: xmltex.fmt pdfxmltex.fmt

xmltex.fmt:
	tex -ini -progname=xmltex "&latex" xmltex.ini

pdfxmltex.fmt:
	pdftex -ini -progname=pdfxmltex "&pdflatex" pdfxmltex.ini
