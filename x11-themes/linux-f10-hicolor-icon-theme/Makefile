# New ports collection makefile for:	x11-themes/linux-f10-hicolor-icon-theme
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	hicolor-icon-theme
PORTVERSION=	0.5
CATEGORIES=	x11-themes linux
MASTER_SITES=	# empty
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	# empty

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A high-color icon theme shell from the FreeDesktop project

CONFLICTS=	linux-hicolor-icon-theme-[0-9]* linux-f8-hicolor-icon-theme-[0-9]*

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
PLIST_FILES=	usr/share/icons/hicolor

do-install:
	${INSTALL} -d ${PREFIX}/usr/share/icons
	${LN} -fs ${LOCALBASE}/share/icons/hicolor ${PREFIX}/usr/share/icons

.include <bsd.port.mk>
