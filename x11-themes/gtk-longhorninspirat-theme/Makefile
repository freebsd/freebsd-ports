# New ports collection makefile for:	Longhorn Inspirat (gtk20 theme/master)
# Date created:				01 Mar 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	longhorninspirat
PORTVERSION=	1.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/files/
PKGNAMEPREFIX=	${TYPE}-
PKGNAMESUFFIX=	-theme
DISTNAME=	Longhorn_Inspirat

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A port of Windows XP theme Longhorn Inspirat

TYPE?=		gtk

THEME_NAME=	"${DISTNAME:S/_/ /}"
WRKSRC=		${WRKDIR}/${THEME_NAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

.if ${TYPE} == "gtk"
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="" METACITY="@comment "
USE_GNOME=	gtk20
.else	# metacity
THEME_DIR=	${PREFIX}/share/gnome/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="@comment " METACITY=""
USE_GNOME=	gnomehier
.endif

post-extract:
	${RM} -r ${WRKSRC}/gtk-2.0/.Trash-roberto

do-install:
	@${MKDIR} ${THEME_DIR}
.if ${TYPE} == "gtk"
	cd ${WRKSRC} && ${FIND} gtk-2.0 | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
	${INSTALL_DATA} ${WRKSRC}/index.theme ${THEME_DIR}
.else
	cd ${WRKSRC} && ${FIND} metacity-1 | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
.endif

.include <bsd.port.mk>
