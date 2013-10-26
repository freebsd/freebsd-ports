# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkvtoolnix
PORTVERSION=	6.4.1
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		CRITICAL

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libebml.so:${PORTSDIR}/textproc/libebml \
		libmatroska.so:${PORTSDIR}/multimedia/libmatroska

USES=		pkgconfig gettext iconv compiler:c++11-lib
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_RAKE=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	ac_cv_path_PO4A=no ZLIB_CFLAGS=-I/usr/include ZLIB_LIBS=-lz
CONFIGURE_ARGS=	--disable-qt \
		--with-boost=${LOCALBASE} \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		--with-boost-regex=boost_regex

OPTIONS_DEFINE=	WXGTK FLAC CURL
OPTIONS_DEFAULT=WXGTK FLAC CURL

BROKEN_sparc64=	Does not install on sparc64

OPTIONS_SUB=	yes
WXGTK_USE=	WX=2.8+
WXGTK_CONFIGURE_ENABLE=	gui
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_WITH=	flac

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	curl
.if defined(BATCH)
MAKE_ENV+=	V=1
.endif

do-build:
	@(cd ${WRKSRC}/; unset PREFIX; ${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}/; unset PREFIX;  ${RAKE_BIN} ${MAKE_ARGS} install)

.include <bsd.port.mk>
