# New ports collection makefile for:	xf86-input-vmmouse
# Date Created:				17 Feb 2006
# Whom:					NIIMI Satoshi <sa2c@sa2c.net>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-vmmouse
PORTVERSION=	12.6.9
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmmouse input driver

XORG_CAT=	driver
CONFIGURE_ARGS=	--with-hal-callouts-dir=${PREFIX}/libexec/hal/scripts
USE_GMAKE=	yes

MAN1=		vmmouse_detect.1
MAN4=		vmmouse.4x

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	The vmmouse protocol is only supported on x86-compatible architectures.

.include <bsd.port.mk>
