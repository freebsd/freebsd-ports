# New ports collection makefile for:	wmfire
# Date created:				21 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	wmfire
PORTVERSION=	0.0.3.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar
DISTNAME=	wmfire-0.0.3.9pre4

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Window Maker dock app showing load average as a flame

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV=	CFLAGS="-I${PREFIX}/include ${CFLAGS}" \
		LIBS="-L${PREFIX}/lib"

.include <bsd.port.mk>
