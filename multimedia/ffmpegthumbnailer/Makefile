# Created by: Dierk Sacher <dierk@blaxxtarz.de>
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	LOCAL/riggs/${PORTNAME}

MAINTAINER=	clutton@zoho.com
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig --enable-gio

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lib jpeg libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	THUMBNAILER
THUMBNAILER_DESC=Register as a system thumbnailer
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=THUMBNAILER

THUMBNAILER_CONFIGURE_ENABLE=	thumbnailer

.include <bsd.port.mk>
