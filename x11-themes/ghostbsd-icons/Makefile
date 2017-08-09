# New ports collection makefile for: ghostbsd wallpaers
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-icons
PORTVERSION=	1.3
CATEGORIES=	x11-themes

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD icons for GTK DE

LICENSE=	CCBYSA
LICENSE_NAME=	CREATIVE COMMON
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/
	${CP} -R ${WRKSRC}/icons/* ${STAGEDIR}${PREFIX}/share/icons
.include <bsd.port.mk>
