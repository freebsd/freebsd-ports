# $FreeBSD$

PORTNAME=	qmmp-plugin-pack
PORTVERSION=	0.10.0
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/plugins/ \
	SF/qmmp-dev/${PORTNAME}/

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Additional plug-ins for QMMP (Qt4)

LICENSE=	GPLv2

CONFLICTS=	${PORTNAME}-qt5-1.*
PORTSCOUT=	limit:^0.*

LIB_DEPENDS=	libqmmpui.so:multimedia/qmmp
BUILD_DEPENDS=	qmmp>=0.10.0:multimedia/qmmp

USES=		cmake:outsource localbase pkgconfig tar:bzip2
USE_QT4=	corelib gui linguisttools_build moc_build qmake_build rcc_build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes

OPTIONS_MULTI=	PLUGINS
OPTIONS_MULTI_PLUGINS=	FFAP MPG123 SRCONV XMP
OPTIONS_DEFAULT=	FFAP MPG123 XMP

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:audio/taglib
FFAP_CMAKE_ON=	-DUSE_FFAP:BOOL=TRUE
FFAP_CMAKE_OFF=	-DUSE_FFAP:BOOL=FALSE
OPTIONS_DEFINE_i386=	FFAPASM
OPTIONS_DEFAULT_i386=	FFAPASM
OPTIONS_DEFINE_amd64=	FFAPASM
OPTIONS_DEFAULT_amd64=	FFAPASM
FFAPASM_DESC=	Optimize FFap decoder using devel/yasm
FFAPASM_BUILD_DEPENDS=	yasm:devel/yasm
FFAPASM_CMAKE_ON=	-DUSE_ASM:BOOL=TRUE
FFAPASM_CMAKE_OFF=	-DUSE_ASM:BOOL=FALSE

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libtag.so:audio/taglib
MPG123_USE=	QT4=uic_build
MPG123_CMAKE_ON=	-DUSE_MPG123:BOOL=TRUE
MPG123_CMAKE_OFF=	-DUSE_MPG123:BOOL=FALSE

SRCONV_DESC=	Support the sample rate converter
SRCONV_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SRCONV_CMAKE_ON=	-DUSE_SRC:BOOL=TRUE
SRCONV_CMAKE_OFF=	-DUSE_SRC:BOOL=FALSE

XMP_DESC=		Support various module formats using libxmp
XMP_LIB_DEPENDS=	libxmp.so:audio/libxmp
XMP_CMAKE_ON=	-DUSE_XMP:BOOL=TRUE
XMP_CMAKE_OFF=	-DUSE_XMP:BOOL=FALSE

pre-configure:
	@${RM} -f ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
