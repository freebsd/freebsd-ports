# New ports collection makefile for:	linux-hicolor-icon-theme
# Date created:		7 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hicolor-icon-theme
PORTVERSION=	0.5
CATEGORIES=	x11-themes linux
MASTER_SITES=	# empty
PKGNAMEPREFIX=	linux-
DISTFILES=	# empty

MAINTAINER=	infofarmer@gmail.com
COMMENT=	A high-color icon theme shell from the FreeDesktop project

RUN_DEPENDS=	${X11BASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

NO_BUILD=	yes
USE_LINUX_PREFIX=	yes

do-install:
	${INSTALL} -d ${PREFIX}/usr/share/icons
	${LN} -fs ${X11BASE}/share/icons/hicolor ${PREFIX}/usr/share/icons

.include <bsd.port.mk>
