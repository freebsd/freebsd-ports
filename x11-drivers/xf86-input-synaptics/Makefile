# $FreeBSD$

PORTNAME=	xf86-input-synaptics
PORTVERSION=	${SYNAPTICS_VERSION}
PORTREVISION=	${SYNAPTICS_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org synaptics input driver

CONFLICTS=	synaptics-[0-9]*

USES=		pathfix
USE_XORG=	x11 xtst
XORG_CAT=	driver

.if defined(WITH_NEW_XORG)
SYNAPTICS_VERSION=	1.7.2
SYNAPTICS_REVISION=	0
PLIST_SUB+=	NEW="" OLD="@comment "
.else
SYNAPTICS_VERSION=	1.6.4
SYNAPTICS_REVISION=	0
PLIST_SUB+=	NEW="@comment " OLD=""
EXTRA_PATCHES+=	${PATCHDIR}/extra-Makefile.in
.endif

.include <bsd.port.mk>
