# New ports collection makefile for:	ranlib
# Date created:		06 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	randlib
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	http://biostatistics.mdanderson.org/SoftwareDownload/ProductDownloadFiles/
DISTNAME=	RANDLIB_V90

MAINTAINER=	bf1783@gmail.com
COMMENT=	Library of Routines for Random Number Generation

USE_LDCONFIG=	yes
MAKE_ENV=	NOPROFILE=true
WRKSRC=		${WRKDIR}/source/randlib.c/src
PORTDOCS=	Basegen.c.doc randlib.c.chs randlib.c.fdoc
PLIST_FILES=	include/randlib.h \
		lib/librandlib.a \
		lib/librandlib.so \
		lib/librandlib.so.1

post-extract:
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/randlib
	@${INSTALL_DATA} ${WRKDIR}/source/randlib.c/doc/* ${PREFIX}/share/doc/randlib
.endif

.include <bsd.port.mk>
