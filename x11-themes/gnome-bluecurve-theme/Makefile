# New ports collection makefile for:	gnome-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-bluecurve-theme

COMMENT=	The Bluecurve GNOME meta-theme

RUN_DEPENDS=	${X11BASE}/share/themes/Bluecurve/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gtk-bluecurve-theme \
		${X11BASE}/share/icons/Bluecurve/index.theme:${PORTSDIR}/x11-themes/icon-bluecurve-theme \
		${X11BASE}/share/gnome/themes/Bluecurve/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-bluecurve-theme

MASTERDIR=	${.CURDIR}/../bluecurve-themes

NO_BUILD=	yes
PLIST_FILES=	share/themes/Bluecurve/index.theme

do-install:
	${MKDIR} ${PREFIX}/share/themes/Bluecurve
	${INSTALL_DATA} ${WRKSRC}/art/index.theme ${PREFIX}/share/themes/Bluecurve

.include "${MASTERDIR}/Makefile"
