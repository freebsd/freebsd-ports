# New ports collection makefile for:    xmltex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xmltex
PORTVERSION=		1.9
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/xmltex/
DISTNAME=		base
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		A non-validating XML parser, written in TeX

BUILD_DEPENDS=		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

WRKSRC=			${WRKDIR}/base
MAKE_ENV=		TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	 ${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt $$TEXMFMAIN/web2c;

post-install: rebuild-tex-database

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

.include <bsd.port.mk>
