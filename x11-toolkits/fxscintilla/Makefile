# New ports collection makefile for:	fxscintilla
# Date created:				16 June 2004
# Whom:                 		Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fxscintilla
PORTVERSION=	1.57
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

LIB_DEPENDS=	FOX-1.0.0:${PORTSDIR}/x11-toolkits/fox

USE_INC_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
