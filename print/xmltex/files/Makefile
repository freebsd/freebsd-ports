# $FreeBSD$

TEX_CMD?=	etex
LATEX_FMT?=	latex
PDFTEX_CMD?=	pdftex
PDFLATEX_FMT?=	pdflatex

all: xmltex.fmt pdfxmltex.fmt

xmltex.fmt:
	${TEX_CMD} -ini -progname=xmltex "&${LATEX_FMT}" xmltex.ini

pdfxmltex.fmt:
	${PDFTEX_CMD} -ini -progname=pdfxmltex "&${PDFLATEX_FMT}" pdfxmltex.ini
