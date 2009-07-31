# New ports collection makefile for:	Digital Harmony (gtk20 theme/master)
# Date created:				08 Sep 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	digital-harmony
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/gtk2/oldies/
PKGNAMEPREFIX=	${TYPE}-
PKGNAMESUFFIX=	-theme
DISTNAME=	Digital-Harmony

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Another popular theme for GNOME desktop

TYPE?=		gtk

THEME_NAME=	${DISTNAME}

NO_BUILD=	yes

.if ${TYPE} == "gtk"
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="" METACITY="@comment "
USE_GNOME=	gtk20
.else	# metacity
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="@comment " METACITY=""
USE_GNOME=	gnomehier
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/gtk-2.0/Scrollbars/Backup \
		${WRKSRC}/gtk-2.0/ReadME.txt
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

do-install:
	@${MKDIR} ${THEME_DIR}
	${INSTALL_DATA} ${WRKSRC}/index.theme ${THEME_DIR}
.if ${TYPE} == "gtk"
	cd ${WRKSRC} && ${FIND} gtk-2.0 | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
.else
	cd ${WRKSRC} && ${FIND} metacity-1 | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}
.endif

.include <bsd.port.mk>
