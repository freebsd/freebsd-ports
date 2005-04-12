# New ports collection makefile for:   libotf
# Date created:                18 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	libotf
PORTVERSION=	0.9.3
CATEGORIES=	print devel
MASTER_SITES=	http://www.m17n.org/libotf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for handling OpenType fonts

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_XLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
