# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-bluecurve-theme

PORTREVISION=	4

COMMENT=	The Bluecurve GNOME meta-theme

RUN_DEPENDS=	${LOCALBASE}/share/themes/Bluecurve/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gtk-bluecurve-theme \
		${LOCALBASE}/share/icons/Bluecurve/index.theme:${PORTSDIR}/x11-themes/icon-bluecurve-theme \
		${LOCALBASE}/share/themes/Bluecurve/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/metacity-bluecurve-theme

MASTERDIR=	${.CURDIR}/../bluecurve-themes

NO_BUILD=	yes
PLIST_FILES=	share/themes/Bluecurve/index.theme

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/themes/Bluecurve
	${INSTALL_DATA} ${WRKSRC}/art/index.theme ${PREFIX}/share/themes/Bluecurve

.include "${MASTERDIR}/Makefile"
