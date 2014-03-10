# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aluminumalloy
PORTVERSION?=	2004.01.04
PORTREVISION?=	7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/gtk2/oldies/
PKGNAMEPREFIX?=	${TYPE}-
PKGNAMESUFFIX?=	-${FLAVOR}-theme
DISTNAME=	aa_${FLAVOR}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Port of Mac OS X theme Aluminum Alloy (${FLAVOR} flavor)

TYPE?=		gtk
FLAVOR?=	volcanic

THEME_NAME=	AluminumAlloy-${FLAVOR:U:C/^(.).*$/\1/g}${FLAVOR:C/^(.)//}
WRKSRC=		${WRKDIR}/${THEME_NAME}

USE_BZIP2=	yes
NO_BUILD=	yes

.if ${TYPE} == gtk
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="" METACITY="@comment "
USE_GNOME=	gtk20
.else	# metacity
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="@comment " METACITY=""
USE_GNOME=	gnomehier
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${THEME_DIR}
.if ${TYPE} == "gtk"
	cd ${WRKSRC} && ${FIND} gtk-2.0 -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${THEME_DIR}
	${INSTALL_DATA} ${WRKSRC}/index.theme ${STAGEDIR}${THEME_DIR}
.else
	cd ${WRKSRC} && ${FIND} metacity-1 -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${THEME_DIR}
.endif

.include <bsd.port.mk>
