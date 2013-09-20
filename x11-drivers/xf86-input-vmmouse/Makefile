# Created by: NIIMI Satoshi <sa2c@sa2c.net>
# $FreeBSD$

PORTNAME=	xf86-input-vmmouse
PORTVERSION=	13.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmmouse input driver

LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal

XORG_CAT=	driver
CONFIGURE_ARGS=	--with-hal-callouts-dir=${PREFIX}/libexec/hal/scripts
USE_GMAKE=	yes

MAN1=		vmmouse_detect.1
MAN4=		vmmouse.4x

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	The vmmouse protocol is only supported on x86-compatible architectures.

.if defined(WITH_NEW_XORG)
PLIST_SUB+=	NEW=""
.else
PLIST_SUB+=	NEW="@comment "
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
