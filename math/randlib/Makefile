# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	randlib
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	https://biostatistics.mdanderson.org/SoftwareDownload/ProductDownloadFiles/ \
		LOCAL/bf
DISTNAME=	RANDLIB_V90

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of Routines for Random Number Generation

USES=		uidfix
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=true
WRKSRC=		${WRKDIR}/source/randlib.c/src
PORTDOCS=	Basegen.c.doc randlib.c.chs randlib.c.fdoc
PLIST_FILES=	include/randlib.h \
		lib/librandlib.a \
		lib/librandlib.so \
		lib/librandlib.so.1

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/source/randlib.c/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
