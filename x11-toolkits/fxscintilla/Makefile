# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	fxscintilla
PORTVERSION=	2.28.0
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fox toolkit reimplementation of Scintilla editing widget

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
