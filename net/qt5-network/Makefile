# $FreeBSD$

PORTNAME=	network
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	net ipv6
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt network module

LIB_DEPENDS=	libproxy.so:net/libproxy
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		ssl
USE_QT5=	core qmake_build buildtools_build
QT_DIST=	base
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	LIBPROXY OPENSSL SSL
QT_CONFIG=	libproxy openssl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${BUILD_WRKSRC}/ssl/qsslsocket_openssl.cpp \
		${BUILD_WRKSRC}/ssl/qsslsocket_openssl_symbols.cpp

post-configure:
	@cd ${WRKSRC}/src/plugins/bearer/generic && \
		${SETENV} ${QMAKE_ENV} ${WRKSRC}/bin/qmake ${QMAKE_ARGS}

post-build:
	@cd ${WRKSRC}/src/plugins/bearer/generic && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@cd ${WRKSRC}/src/plugins/bearer/generic && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
