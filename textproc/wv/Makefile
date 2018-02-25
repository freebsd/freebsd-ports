# Created by: sumikawa@kame.net
# $FreeBSD$

PORTNAME=	wv
PORTVERSION=	1.2.9
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/wv/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library and executables to access Microsoft Word files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libwmf.so:graphics/libwmf

USES=		gmake jpeg pkgconfig libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"
CONFIGURE_ARGS=	--with-png=${LOCALBASE} \
		--with-libwmf=${LOCALBASE}
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
MAKE_ARGS+=	INSTALL_STRIP_FLAG="${STRIP}"
USE_GNOME=	libgsf
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
