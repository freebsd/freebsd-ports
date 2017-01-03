# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkvtoolnix
PORTVERSION=	9.7.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		https://mkvtoolnix.download/sources/

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libebml.so:textproc/libebml \
		libboost_regex.so:devel/boost-libs \
		libmatroska.so:multimedia/libmatroska

BROKEN_sparc64=	does not install

USES=		compiler:c++14-lang iconv localbase pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
CONFIGURE_ENV+=	ac_cv_path_PO4A=no
CONFIGURE_ARGS=	--without-curl \
		--with-boost=${LOCALBASE} \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		--with-boost-regex=boost_regex
MAKE_ENV=	V=1

OPTIONS_DEFINE=	FLAC NLS QT5
OPTIONS_DEFAULT=	FLAC QT5
OPTIONS_SUB=	yes

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_WITH=	flac

NLS_USES=	gettext
NLS_CONFIGURE_WITH=	gettext

QT5_DESC=	Build and install GUI application (Qt 5)
QT5_USES=	desktop-file-utils shared-mime-info
QT5_USE=	QT5=buildtools_build,concurrent,core,gui,network,quick,widgets
QT5_CONFIGURE_ENABLE=	qt

.include <bsd.port.options.mk>

post-patch:
.if ${OSVERSION} < 1000000
	@${REINPLACE_CMD} -e 's|std::llround|llround|g' \
		${WRKSRC}/src/common/hevc.cpp \
		${WRKSRC}/src/common/mpeg4_p10.cpp \
		${WRKSRC}/src/common/theora.cpp \
		${WRKSRC}/src/extract/cuesheets.cpp \
		${WRKSRC}/src/extract/xtr_avi.cpp \
		${WRKSRC}/src/info/mkvinfo.cpp \
		${WRKSRC}/src/input/r_avi.cpp \
		${WRKSRC}/src/input/r_matroska.cpp \
		${WRKSRC}/src/input/r_ogm.cpp \
		${WRKSRC}/src/input/r_tta.cpp \
		${WRKSRC}/src/merge/cluster_helper.h \
		${WRKSRC}/src/merge/generic_packetizer.cpp \
		${WRKSRC}/src/merge/output_control.cpp \
		${WRKSRC}/src/merge/timestamp_factory.h \
		${WRKSRC}/src/output/p_dirac.cpp \
		${WRKSRC}/src/output/p_hevc.cpp \
		${WRKSRC}/src/output/p_mpeg4_p10.cpp \
		${WRKSRC}/src/output/p_tta.cpp \
		${WRKSRC}/src/output/p_wavpack.cpp
	@${REINPLACE_CMD} -e 's|std::lround|lround|g' \
		${WRKSRC}/src/propedit/tag_target.cpp
.endif
	@${REINPLACE_CMD} -e '/LIBS="-lintl/s,-liconv,$$ICONV_LIBS,' \
		${WRKSRC}/configure

post-configure-NLS-off:
# https://github.com/mbunkus/mkvtoolnix/issues/1501
# Fixed in 8.6.0
	@${REINPLACE_CMD} -e 's|LIBINTL_LIBS =|#LIBINTL_LIBS =|g' ${WRKSRC}/build-config
	@${REINPLACE_CMD} -e 's|#define HAVE_LIBINTL_H|//#define HAVE_LIBINTL_H|g' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's|S["LIBINTL_LIBS"]=|#S["LIBINTL_LIBS"]=|g' ${WRKSRC}/config.status

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV:NPREFIX=*} ./drake ${_MAKE_JOBS})

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV:NPREFIX=*} \
		./drake ${_MAKE_JOBS} ${MAKE_ARGS} install)

.include <bsd.port.mk>
