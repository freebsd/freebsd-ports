# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	fxscintilla
PORTVERSION=	2.28.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

LICENSE=	LGPL21 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
