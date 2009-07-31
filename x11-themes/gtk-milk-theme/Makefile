# New ports collection makefile for:	Milk (gtk20 theme/master)
# Date created:				28 Feb 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-milk-theme/Makefile,v 1.4 2007/08/07 04:37:40 mezz Exp $
#

PORTNAME=	milk
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/gtk2/oldies/
PKGNAMEPREFIX?=	${TYPE}-
PKGNAMESUFFIX=	-theme
DISTNAME=	Milk-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A port of Milk, Mac OS X theme

TYPE?=		gtk

THEME_NAME=	Milk

USE_BZIP2=	yes
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
