# New ports collection makefile for:	xisp
# Date created:		June 24, 1999
# Whom:			morishim@cig.mot.com
#
# $FreeBSD$
#

PORTNAME=	xisp
PORTVERSION=	2.6
CATEGORIES=	net
MASTER_SITES=	http://www.ml-search.com/xisp/distfiles/
DISTFILES=	xisp-2.6-noufc.tar.gz \
		xisp-2.6-freebsd-patch.tar.gz

MAINTAINER=	morishim@cig.mot.com

LIB_DEPENDS=	xforms:${PORTSDIR}/x11-toolkits/xforms

USE_XPM=	yes
WRKSRC=		${WRKDIR}/xisp-2.6
MAN1=		xisp.1
HAS_CONFIGURE=	yes
.if defined(WITH_DES)
CONFIGURE_ENV=	USE_DESLIB="yes"
.else
CONFIGURE_ENV=	USE_DESLIB="no"
.endif

.include <bsd.port.mk>
