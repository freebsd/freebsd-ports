# Created by: Gerald Pfeifer <gerald@pfeifer.com>
# $FreeBSD$

PORTNAME=	bibtex2html
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	textproc print
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Tools for searching BibTeX and translating from BibTeX to HTML

BUILD_DEPENDS=	ocaml:lang/ocaml

USES=		perl5
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	PDFDOCS
PDFDOCS_DESC=	${DOCS_DESC}

PDFDOCS_CONFIGURE_ENABLE=	doc
PDFDOCS_USE=	TEX=latex:build
PDFDOCS_BUILD_DEPENDS=	hevea:textproc/hevea
PDFDOCS_INSTALL_TARGET=	install install-doc

PLIST_FILES=	bin/aux2bib bin/bib2bib bin/bibtex2html \
		man/man1/bibtex2html.1.gz man/man1/bib2bib.1.gz man/man1/aux2bib.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDFDOCS}
PORTDOCS=	*
.endif

.include <bsd.port.mk>
