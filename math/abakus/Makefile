# New ports collection makefile for:    abakus
# Date created:                         3 January 2005
# Whom:                                 Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	abakus
PORTVERSION=	0.91
PORTREVISION=	4
CATEGORIES=	math kde
MASTER_SITES=	http://grammarian.homelinux.net/abakus/ \
		http://www.athame.co.uk/mirror/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andy@athame.co.uk
COMMENT=	Michael Pyne's Abakus Calculator

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

USE_BISON=	build
PREFIX=		${LOCALBASE}
USE_KDELIBS_VER=3
_NO_KDE_CONFTARGET_HACK=	yes
QT_NONSTANDARD=	yes

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
PREFIX=		${LOCALBASE}

.include <bsd.port.mk>
