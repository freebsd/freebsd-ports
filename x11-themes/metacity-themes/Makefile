# New ports collection makefile for:	GNOME Metacity Themes
# Date created:				06 Mar 2004
# Whom:					Remington Lang <MrL0L@charter.net>
#
# $FreeBSD$

# Port logic stolen from x11-themes/kde-icons-noia by
# lioux@.

PORTNAME=	metacity-themes
PORTVERSION=	20040306
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	# Empty
DISTFILES=	# Empty
EXTRACT_ONLY=	# Empty

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	Meta-port for Gnome Metacity themes

RUN_DEPENDS=	${X11BASE}/share/gnome/themes/Alloy-C/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-theme-alloy-c \
		${X11BASE}/share/gnome/themes/Hacked-2/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-theme-hacked-2 \
		${X11BASE}/share/gnome/themes/Iridium-Rounded/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-theme-iridium-rounded \
		${X11BASE}/share/gnome/themes/microgui/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-theme-microgui

NO_BUILD=	yes

do-install:    # Empty

.include <bsd.port.mk>
