# $FreeBSD$

PORTNAME=	qmmp-plugin-pack
PORTVERSION=	0.7.3
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

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	FFAP MPG123 QSUI
OPTIONS_DEFAULT=	FFAP MPG123 QSUI

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
FFAP_CMAKE_ON=	-DUSE_FFAP:BOOL=TRUE
FFAP_CMAKE_OFF=	-DUSE_FFAP:BOOL=FALSE
OPTIONS_DEFINE_i386=	FFAPASM
OPTIONS_DEFAULT_i386=	FFAPASM
OPTIONS_DEFINE_amd64=	FFAPASM
OPTIONS_DEFAULT_amd64=	FFAPASM
FFAPASM_DESC=	Optimize FFap decoder using devel/yasm
FFAPASM_BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
FFAPASM_CMAKE_ON=	-DUSE_ASM:BOOL=TRUE
FFAPASM_CMAKE_OFF=	-DUSE_ASM:BOOL=FALSE

MPG123_LIB_DEPENDS=	libmpg123.so:${PORTSDIR}/audio/mpg123
MPG123_USE=	QT4=uic_build
MPG123_CMAKE_ON=	-DUSE_MPG123:BOOL=TRUE
MPG123_CMAKE_OFF=	-DUSE_MPG123:BOOL=FALSE

QSUI_DESC=		Simple UI based on standard widgets set
QSUI_USE=	QT4=network,uic_build
QSUI_CMAKE_ON=	-DUSE_QSUI:BOOL=TRUE
QSUI_CMAKE_OFF=	-DUSE_QSUI:BOOL=FALSE

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:PATH=${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	@${RM} -f ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.post.mk>
