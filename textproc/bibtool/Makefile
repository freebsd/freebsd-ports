# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	bibtool
PORTVERSION=	2.48
PORTREVISION=	5
CATEGORIES=	textproc print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	biblio/bibtex/utils/${PORTNAME}
DISTNAME=	BibTool-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Command line manipulation of BibTeX files

USE_TEX=	latex:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MAKEFILE=	makefile
INSTALL_TARGET=	install install.man

PORTDOCS=	bibtool.dvi ref_card.dvi c_lib.dvi

post-build:
	cd ${WRKSRC} && ${MAKE} doc && ${MAKE} doc

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_MAN} ${WRKSRC}/Doc/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
