# Created by: NIIMI Satoshi <sa2c@sa2c.net>
# $FreeBSD$

PORTNAME=	xf86-input-vmmouse
PORTVERSION=	13.1.0
PORTREVISION=	3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmmouse input driver

LIB_DEPENDS=	libhal.so:sysutils/hal

USES=		gmake xorg-cat:driver
CONFIGURE_ARGS=	--with-hal-callouts-dir=${PREFIX}/libexec/hal/scripts

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	The vmmouse protocol is only supported on x86-compatible architectures.

.include <bsd.port.mk>
