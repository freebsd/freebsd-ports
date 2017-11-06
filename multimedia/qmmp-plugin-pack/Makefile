# $FreeBSD$

PORTNAME=	qmmp-plugin-pack
PORTVERSION=	0.10.3
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/plugins/ \
	SF/qmmp-dev/${PORTNAME}/

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Additional plug-ins for QMMP (Qt4)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqmmpui.so:multimedia/qmmp
BUILD_DEPENDS=	qmmp>=0.10.0:multimedia/qmmp

USES=		cmake:outsource localbase pkgconfig tar:bzip2
USE_QT4=	corelib gui linguisttools_build moc_build qmake_build rcc_build
USE_LDCONFIG=	yes

CONFLICTS=	${PORTNAME}-qt5-1.*
PORTSCOUT=	limit:^0.*

OPTIONS_DEFAULT=	FFAP MPG123 XMP
OPTIONS_MULTI=	PLUGINS
OPTIONS_MULTI_PLUGINS=	FFAP MPG123 SRCONV XMP
OPTIONS_SUB=	yes

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:audio/taglib
FFAP_CMAKE_BOOL=	USE_FFAP
OPTIONS_DEFINE_i386=	FFAPASM
OPTIONS_DEFAULT_i386=	FFAPASM
OPTIONS_DEFINE_amd64=	FFAPASM
OPTIONS_DEFAULT_amd64=	FFAPASM
FFAPASM_DESC=	Optimize FFap decoder using devel/yasm
FFAPASM_BUILD_DEPENDS=	yasm:devel/yasm
FFAPASM_CMAKE_BOOL=	USE_ASM

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libtag.so:audio/taglib
MPG123_USE=	QT4=uic_build
MPG123_CMAKE_BOOL=	USE_MPG123

SRCONV_DESC=	Support the sample rate converter
SRCONV_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SRCONV_CMAKE_BOOL=	USE_SRC

XMP_DESC=		Support various module formats using libxmp
XMP_LIB_DEPENDS=	libxmp.so:audio/libxmp
XMP_CMAKE_BOOL=	USE_XMP

pre-configure:
	@${RM} ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
