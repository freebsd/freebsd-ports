# Ports collection makefile for:	xmbmon
# Date created:				2001/08/30
# Whom:					kaz@kobe1995.net (NAKAMURA Kauzushi)
#
# $FreeBSD$
#

PORTNAME=	xmbmon
PORTREVISION=	9

COMMENT=	X motherboard monitor for LM78/79, W8378x, AS99127F, VT82C686, and ADM9240

MASTERDIR=	${.CURDIR}/../mbmon

USE_XORG=	x11 xt
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

PLIST_FILES=	lib/X11/app-defaults/XMBmon
MAN1=		xmbmon.1x

post-install:
	${MKDIR} ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/xmbmon.resources ${PREFIX}/lib/X11/app-defaults/XMBmon

.include "${MASTERDIR}/Makefile"
