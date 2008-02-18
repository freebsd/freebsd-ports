# New ports collection Makefile for:		tapioca-qt
# Date created:					2008-02-10
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	tapioca-qt
PORTVERSION=	0.14.1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tapioca-voip

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Framework for VoIP and IP applications

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	QtTelepathyCore.0:${PORTSDIR}/net-im/telepathy-qt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=DEBUG \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}"
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake uic moc rcc
USE_LDCONFIG=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../CMakeLists.txt

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

.include <bsd.port.mk>
