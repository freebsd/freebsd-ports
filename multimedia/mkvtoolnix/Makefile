# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkvtoolnix
PORTVERSION=	6.3.0
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		CRITICAL

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg \
		boost_regex:${PORTSDIR}/devel/boost-libs \
		ebml:${PORTSDIR}/textproc/libebml \
		matroska:${PORTSDIR}/multimedia/libmatroska

USES=		pkgconfig gettext iconv
USE_XZ=		yes
USE_GCC=	4.6+
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
MAKE_JOBS_SAFE=	yes

MANLANG=	"" ja zh_CN nl uk
MAN1=		mkvextract.1 mkvinfo.1 mkvmerge.1 mkvpropedit.1

OPTIONS_DEFINE=	WXGTK FLAC CURL
OPTIONS_DEFAULT=WXGTK FLAC CURL

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.if defined(BATCH)
MAKE_ENV+=	V=1
.endif

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.8+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
MAN1+=		mmg.1
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--with-flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

do-build:
	@(cd ${WRKSRC}/; unset PREFIX; ${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}/; unset PREFIX;  ${RAKE_BIN} install)

.include <bsd.port.post.mk>
