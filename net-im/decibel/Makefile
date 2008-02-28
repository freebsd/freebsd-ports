# New ports collection Makefile for:	decibel
# Date created:				2008-02-10
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	decibel
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://decibel.kde.org/fileadmin/downloads/decibel/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Realtime communications framework

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	QtTapioca.0:${PORTSDIR}/net-im/tapioca-qt

USE_QT_VER=	4
QT_COMPONENTS=	corelib xml dbus moc uic rcc qtestlib
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=DEBUG \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}"

.include <bsd.port.pre.mk>

.if (${ARCH} == amd64) && (${OSVERSION} < 600000)
BROKEN=		Does not compile
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../src/client/Decibel/CMakeLists.txt

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

.include <bsd.port.post.mk>
