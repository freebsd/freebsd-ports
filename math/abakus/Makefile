# New ports collection makefile for:    abakus
# Date created:                         3 January 2005
# Whom:                                 Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	abakus
PORTVERSION=	0.91
PORTREVISION=	6
CATEGORIES=	math kde
MASTER_SITES=	http://purinchu.net/abakus/ \
		http://www.athame.co.uk/mirror/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Michael Pyne's Abakus Calculator

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_KDELIBS_VER=3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	bison=no flex=no prefix=${PREFIX} extraincludes=${LOCALBASE}
_NO_KDE_CONFTARGET_HACK=	yes
QT_NONSTANDARD=	yes

.include <bsd.port.mk>
