# New ports collection makefile for:    Ana
# Date created:         20 Feb 2005
# Whom:                 Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ana
PORTVERSION=	0.11
PORTREVISION=	10
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://ana.netart.eu.org/
PKGNAMEPREFIX=	${TYPE}-
PKGNAMESUFFIX=	-theme
DISTNAME=	Ana

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clean and white GTK engine

LIB_DEPENDS=	rsvg-2:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${LOCALBASE}/share/icons/Foxtrot/index.theme:${PORTSDIR}/x11-themes/gnome-themes-extras

TYPE?=		gtk
THEME_NAME=	Ana
WRKSRC=		${WRKDIR}/${DISTNAME}

NO_BUILD=	yes

.if ${TYPE} == "gtk"
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK=""
PLIST_SUB+=	GTK20=""
PLIST_SUB+=	METACITY="@comment "
USE_GNOME=	gtk20
.else   # metacity
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK="@comment "
PLIST_SUB+=	GTK20="@comment "
PLIST_SUB+=	METACITY=""
USE_GNOME=	gnomehier
.endif

PLIST_SUB+=	THEME_NAME="${THEME_NAME}"

do-install:
	@${MKDIR} ${THEME_DIR}
.if ${TYPE} == "gtk"
	cd ${WRKSRC} && ${FIND} gtk-2.0 -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
	cd ${WRKSRC} && ${FIND} gtk  -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
	cd ${WRKSRC} && ${FIND} icons -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
	${INSTALL_DATA} ${WRKSRC}/index.theme ${THEME_DIR}
.else
	cd ${WRKSRC} && ${FIND} metacity-1 -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
.endif

.include <bsd.port.mk>
