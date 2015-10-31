# $FreeBSD$

PORTNAME=	openh264
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=v
PORTREVISION=	5
CATEGORIES=	multimedia

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Cisco implementation of H.264 codec

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

USES=		compiler cpe gmake
CPE_VENDOR=	cisco
USE_LDCONFIG=	yes
ASFLAGS+=	${ASFLAGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS=	OS=freebsd ARCH="${ARCH:S/amd64/x86_64/}" \
		CCASFLAGS='$$(CFLAGS) ${ASFLAGS}' \
		CFLAGS_OPT="" CFLAGS_DEBUG=""
ALL_TARGET=	all

OPTIONS_DEFINE=	DEBUG PLUGINS TEST
OPTIONS_DEFAULT=PLUGINS
OPTIONS_SUB=	yes

DEBUG_BUILD_DEPENDS_OFF=	${DEBUG_BUILD_DEPENDS_OFF_${ARCH}}
DEBUG_BUILD_DEPENDS_OFF_amd64=	nasm:${PORTSDIR}/devel/nasm
DEBUG_BUILD_DEPENDS_OFF_i386=	nasm:${PORTSDIR}/devel/nasm
DEBUG_MAKE_ARGS=BUILDTYPE=Debug
PLUGINS_BUILD_DEPENDS=gmp-api>=34.0:${PORTSDIR}/multimedia/gmp-api
#			gmp-api<36.0:${PORTSDIR}/multimedia/gmp-api
PLUGINS_CFLAGS=	-I${LOCALBASE}/include/gmp-api
PLUGINS_MAKE_ARGS=HAVE_GMP_API=Yes
PLUGINS_ALL_TARGET=plugin
PLUGINS_USES=	webplugin:gecko
WEBPLUGIN_NAME=	gmp-gmp${PORTNAME}
WEBPLUGIN_FILES=gmp${PORTNAME}.info libgmp${PORTNAME}.so
SUB_FILES+=	gmp${PORTNAME}.js
SUB_LIST+=	PORTVERSION=${PORTVERSION} TIMESTAMP="`date +%s`"

TEST_BUILD_DEPENDS=googletest>=1.6.0:${PORTSDIR}/devel/googletest
TEST_CFLAGS=	-I${LOCALBASE}/include
TEST_MAKE_ARGS=	HAVE_GTEST=Yes
TEST_ALL_TARGET=test

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG} && (${ARCH:Maarch*} || ${ARCH:Marm*} )
USE_BINUTILS=	yes
ASFLAGS_clang=	-no-integrated-as
.endif

post-patch:
	${REINPLACE_CMD} -e '/gtest-targets\.mk/d' \
		-e '/pkgconfig/s/lib/libdata/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,@prefix@,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pc.in

pre-build:
	${LN} -sf ${LOCALBASE}/lib/libgtest.so ${WRKSRC}/libgtest.a

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0

post-install-PLUGINS-on:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/gmp${PORTNAME}.info ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/libgmp${PORTNAME}.so ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_DATA} ${WRKDIR}/gmp${PORTNAME}.js ${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>
