# Created by: Andrei V. Shetuhin <reki@reki.ru>
# $FreeBSD$

PORTNAME=	ctpp2
PORTVERSION=	2.8.3
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://ctpp.havoc.ru/download/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	C++ library to use templates in C/C++ projects, version 2

USES=		cmake gettext iconv:build
USE_LDCONFIG=	yes
USE_GCC=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=		ctpp2c.1 ctpp2vm.1 ctpp2i.1 ctpp2json.1 ctpp2-config.1

OPTIONS_DEFINE=	DEBUG DISCARD_ILSEQ DOCS MD5 OPTIMIZATION TRANSLITERATE
OPTIONS_DEFAULT=	DISCARD_ILSEQ MD5 OPTIMIZATION TRANSLITERATE
DEBUG_DESC=		Enable debug output
OPTIMIZATION_DESC=	Enable optimization
MD5_DESC=		Enable md5 support
DISCARD_ILSEQ_DESC=	Discard illegal sequence and continue
TRANSLITERATE_DESC=	Enable transliteration in the conversion

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DDEBUG_MODE=ON
.else
CMAKE_ARGS+=	-DDEBUG_MODE=OFF
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
CMAKE_ARGS+=	-DENABLE_DOCS=ON
PLIST_SUB+=	DOCS=""
.else
CMAKE_ARGS+=	-DENABLE_DOCS=OFF
PLIST_SUB+=	DOCS="@comment "
.endif

.if ${PORT_OPTIONS:MMD5}
CMAKE_ARGS+=	-DMD5_SUPPORT=ON
.else
CMAKE_ARGS+=	-DMD5_SUPPORT=OFF
.endif

.if ${PORT_OPTIONS:MDISCARD_ILSEQ}
CMAKE_ARGS+=	-DICONV_DISCARD_ILSEQ=ON
.else
CMAKE_ARGS+=	-DICONV_DISCARD_ILSEQ=OFF
.endif

.if ${PORT_OPTIONS:MTRANSLITERATE}
CMAKE_ARGS+=	-DICONV_TRANSLITERATE=ON
.else
CMAKE_ARGS+=	-DICONV_TRANSLITERATE=OFF
.endif

.if ${PORT_OPTIONS:MOPTIMIZATION}
CMAKE_ARGS+=	-DENABLE_OPTIMIZATION=ON
.else
CMAKE_ARGS+=	-DENABLE_OPTIMIZATION=OFF
.endif

.include <bsd.port.mk>
