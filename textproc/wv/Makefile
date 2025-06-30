PORTNAME=	wv
PORTVERSION=	1.2.9
PORTREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/wv/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library and executables to access Microsoft Word files
WWW=		https://wvware.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libwmf.so:graphics/libwmf

USES=		gmake gnome jpeg pkgconfig libtool xorg
USE_GNOME=	libgsf
USE_LDCONFIG=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-png=${LOCALBASE} \
		--with-libwmf=${LOCALBASE}
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
	INSTALL_STRIP_FLAG="${STRIP}"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
