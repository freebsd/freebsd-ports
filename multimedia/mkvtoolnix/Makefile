# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkvtoolnix
PORTVERSION=	54.0.0
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		https://mkvtoolnix.download/sources/

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	does not install

BUILD_DEPENDS=	rake:devel/rubygem-rake \
		docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libebml.so:textproc/libebml \
		libboost_regex.so:devel/boost-libs \
		libpugixml.so:textproc/pugixml \
		libmatroska.so:multimedia/libmatroska \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c++17-lang iconv localbase pkgconfig tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_PO4A=no
CONFIGURE_ARGS=	--with-boost=${LOCALBASE} \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		--with-boost-regex=boost_regex \
		--with-docbook-xsl-root=${PREFIX}/share/xsl/docbook
MAKE_ENV=	V=1
MAKE_CMD=	rake -v
MAKEFILE=	Rakefile
ALL_TARGET=	#Empty

OPTIONS_DEFINE=	DVDREAD FLAC NLS QT5 MANTRANS
OPTIONS_DEFAULT=	FLAC QT5
OPTIONS_SUB=	yes

.if !defined(DEFAULT_VERSIONS) || ! ${DEFAULT_VERSIONS:Mssl=*}
# Blocked by net/qt5-network: cannot use QT5 with default OpenSSL
OPTIONS_EXCLUDE_FreeBSD_11+=	QT5
.endif

DVDREAD_DESC=		Support reading DVD chapters via libdvdread
DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_WITH=	dvdread

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_WITH=	flac

NLS_USES=	gettext
NLS_CONFIGURE_WITH=	gettext

QT5_DESC=	Build and install GUI application (Qt 5)
QT5_USES=	desktop-file-utils qt:5 shared-mime-info
QT5_USE=	QT=buildtools_build,concurrent,core,dbus,declarative,gui,multimedia,network,widgets
QT5_CONFIGURE_ENABLE=	qt
QT5_BUILD_DEPENDS=	qmake:devel/qt5-qmake
QT5_LIB_DEPENDS=	libcmark.so:textproc/cmark

MANTRANS_DESC=		Build and install manpage translations
MANTRANS_BUILD_DEPENDS=	po4a:textproc/po4a

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} != clang
USE_CXXSTD=	c++17
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS="-lintl/s,-liconv,$$ICONV_LIBS,' \
		${WRKSRC}/configure

post-configure-NLS-off:
# https://github.com/mbunkus/mkvtoolnix/issues/1501
# Fixed in 8.6.0
	@${REINPLACE_CMD} -e 's|LIBINTL_LIBS =|#LIBINTL_LIBS =|g' ${WRKSRC}/build-config
	@${REINPLACE_CMD} -e 's|#define HAVE_LIBINTL_H|//#define HAVE_LIBINTL_H|g' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's|S["LIBINTL_LIBS"]=|#S["LIBINTL_LIBS"]=|g' ${WRKSRC}/config.status

.include <bsd.port.post.mk>
