# New ports collection makefile for:    bibtex2html
# Date created:         2002-01-21
# Whom:			Gerald Pfeifer <gerald@pfeifer.com>
#
# $FreeBSD$
#

PORTNAME=	bibtex2html
PORTVERSION=	1.94
CATEGORIES=	textproc print
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Tools for searching BibTeX and translating from BibTeX to HTML

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

GNU_CONFIGURE=	yes

MAN1=		bibtex2html.1 bib2bib.1 aux2bib.1
PLIST_FILES=	bin/aux2bib bin/bib2bib bin/bibtex2html

.include <bsd.port.mk>
