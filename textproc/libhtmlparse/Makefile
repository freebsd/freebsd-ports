# New ports collection makefile for:   libhtmlparse
# Date created:        1 January 2005
# Whom:                Mooneer Salem <mooneer@translator.cx>
#
# $FreeBSD$
#

PORTNAME=	libhtmlparse
PORTVERSION=	0.2.0
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.translator.cx/dist/libs/

MAINTAINER=	mooneer@translator.cx
COMMENT=	Simple and fast HTML parsing library for C programs

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
