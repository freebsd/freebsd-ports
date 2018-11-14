# $FreeBSD$

PORTNAME=	network
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	net ipv6
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt network module

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		compiler:c++11-lang qmake:no_env qt-dist:5,base ssl
USE_QT=		core buildtools_build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	OPENSSL SSL
QT_CONFIG=	openssl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${BUILD_WRKSRC}/ssl/qsslsocket_openssl.cpp
	@${REINPLACE_CMD} -e 's|%%OPENSSLLIB%%|${OPENSSLLIB}|g' \
		${BUILD_WRKSRC}/ssl/qsslsocket_openssl_symbols.cpp

post-configure:
.for d in src/network src/plugins/bearer/generic
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

post-build:
	@cd ${WRKSRC}/src/plugins/bearer/generic && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@cd ${WRKSRC}/src/plugins/bearer/generic && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
