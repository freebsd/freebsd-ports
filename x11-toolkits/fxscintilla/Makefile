# New ports collection makefile for:	fxscintilla
# Date created:				16 June 2004
# Whom:                 		Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fxscintilla
PORTVERSION=	2.28.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

LICENSE=	LGPL21 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
