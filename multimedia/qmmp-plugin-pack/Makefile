# $FreeBSD$

PORTNAME=	qmmp-plugin-pack
PORTVERSION=	0.7.2
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/plugins/ \
		http://qmmp.googlecode.com/files/

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Additional plug-ins for QMMP

LICENSE=	GPLv2

LIB_DEPENDS=	libqmmpui.so:${PORTSDIR}/multimedia/qmmp
BUILD_DEPENDS=	qmmp>=0.7.0:${PORTSDIR}/multimedia/qmmp

USE_BZIP2=	yes
USES=		cmake:outsource pkgconfig
USE_QT4=	corelib gui qmake_build rcc_build moc_build linguist_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FFAP MPG123 QSUI
OPTIONS_DEFAULT=	FFAP MPG123 QSUI
FFAP_DESC=		Support APE sound file
MPG123_DESC=	Support libmpg123 (MPEG v1/2 layer1/2/3)
QSUI_DESC=		Simple UI based on standard widgets set
OPTIONS_DEFINE_i386=	FFAPASM
OPTIONS_DEFAULT_i386=	FFAPASM
OPTIONS_DEFINE_amd64=	FFAPASM
OPTIONS_DEFAULT_amd64=	FFAPASM
FFAPASM_DESC=	Optimize FFap decoder using devel/yasm

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQSUI}
USE_QT4+=	network
PLIST_SUB+=	QSUI=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_QSUI:BOOL=TRUE
.else
PLIST_SUB+=	QSUI="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_QSUI:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MMPG123}
PLIST_SUB+=	MPG123=""
LIB_DEPENDS+=	libmpg123.so:${PORTSDIR}/audio/mpg123
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=TRUE
.else
PLIST_SUB+=	MPG123="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=FALSE
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFFAP}
PLIST_SUB+=	FFAP=""
. if (${ARCH} == i386 || ${ARCH} == amd64) && ${PORT_OPTIONS:MFFAPASM}
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ASM:BOOL=TRUE
. else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ASM:BOOL=FALSE
. endif
LIB_DEPENDS+=	libtag.so:${PORTSDIR}/audio/taglib
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FFAP:BOOL=TRUE
.else
PLIST_SUB+=	FFAP="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FFAP:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MQSUI} || ${PORT_OPTIONS:MMPG123}
USE_QT4+=	uic_build
.endif

CMAKE_ARGS+=	${PLUGIN_OPTIONS_CMAKE} \
	-DCMAKE_REQUIRED_INCLUDES:PATH=${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	${RM} -f ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.post.mk>
