# New ports collection makefile for:	cloop-utils
# Date created:				19 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cloop-utils
PORTVERSION=	2.00
CATEGORIES=	sysutils
MASTER_SITES=	http://developer.linuxtag.net/knoppix/sources/
DISTNAME=	cloop_${PORTVERSION}-1

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Compressed loop FS utils

WRKSRC=		${WRKDIR}/cloop-${PORTVERSION}
USE_GMAKE=	yes
MAKE_ENV=	APPSONLY=yes
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/create_compressed_fs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/extract_compressed_fs ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
