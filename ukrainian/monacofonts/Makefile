# New ports collection makefile for: koi8rPS
# Date created:         22 July 1999
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	monaco
PORTVERSION=	1.0
CATEGORIES=	ukrainian x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of 5 "fixed" fonts for X11 from www.brama.com

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86

USE_ZIP=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/Monaco.bdf

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"
MAKE_ARGS+=	-j 2

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
