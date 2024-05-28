PORTNAME=	bibtex2html
PORTVERSION=	1.99
PORTREVISION=	2
CATEGORIES=	textproc print
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Tools for searching BibTeX and translating from BibTeX to HTML
WWW=		https://www.lri.fr/~filliatr/bibtex2html/

LICENSE=	GPLv2

BUILD_DEPENDS=	ocaml:lang/ocaml

USES=		gmake perl5

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aux2bib bin/bib2bib bin/bibtex2html \
		share/man/man1/bibtex2html.1.gz share/man/man1/bib2bib.1.gz share/man/man1/aux2bib.1.gz

OPTIONS_DEFINE=	PDFDOCS

PDFDOCS_DESC=	${DOCS_DESC}

PDFDOCS_BROKEN=	pdfTeX error: pdflatex (file cm-super-t1.enc): cannot open encoding file for r
PDFDOCS_BUILD_DEPENDS=	hevea:textproc/hevea
PDFDOCS_USES=	tex
PDFDOCS_USE=	TEX=latex:build
PDFDOCS_CONFIGURE_ENABLE=	doc
PDFDOCS_INSTALL_TARGET=	install install-doc

.include <bsd.port.mk>
