# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkvtoolnix
PORTVERSION=	7.1.0
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		CRITICAL

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg \
		libebml.so:${PORTSDIR}/textproc/libebml \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libmatroska.so:${PORTSDIR}/multimedia/libmatroska

USES=		pkgconfig gettext iconv compiler:c++11-lib tar:xz
GNU_CONFIGURE=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	ac_cv_path_PO4A=no ZLIB_CFLAGS=-I/usr/include ZLIB_LIBS=-lz
CONFIGURE_ARGS=	--disable-qt \
		--with-boost=${LOCALBASE} \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		--with-boost-regex=boost_regex \
		--without-curl

OPTIONS_DEFINE=	WXGTK FLAC
OPTIONS_DEFAULT=WXGTK FLAC

BROKEN_sparc64=	Does not install on sparc64

OPTIONS_SUB=	yes
WXGTK_USES=	desktop-file-utils shared-mime-info
WXGTK_USE=	wx=3.0
WXGTK_CONFIGURE_ENABLE=	gui
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_WITH=	flac

.if defined(BATCH)
MAKE_ENV+=	V=1
.endif

do-build:
	@(cd ${WRKSRC}/; unset PREFIX; ./drake ${_MAKE_JOBS})

do-install:
	@(cd ${WRKSRC}/; unset PREFIX;  ./drake ${_MAKE_JOBS} ${MAKE_ARGS} install)

.include <bsd.port.mk>
