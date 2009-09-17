# New ports collection makefile for:	conky
# Date created:				2005-08-27
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-awesome

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	An advanced, highly configurable system monitor (configured for x11-wm/awesome)

MASTERDIR=	${.CURDIR}/../../sysutils/conky
DESCR=		${.CURDIR}/pkg-descr

CONFLICTS=	conky-[0-9]*

USE_XORG=	# This is a comment
USE_GNOME=	pkgconfig
CONFIGURE_ARGS+=	--disable-x11 --disable-own-window

.include "${MASTERDIR}/Makefile"
