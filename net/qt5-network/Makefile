PORTNAME=	network
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	net
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt network module

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		compiler:c++11-lang qmake:no_env qt-dist:5,base ssl
USE_QT=		core buildtools_build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	OPENSSL SSL
QT_CONFIG=	openssl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} == "base"
# 1200085	339270	October 19, 2018	12.0-STABLE after updating OpenSSL to version 1.1.1.
BROKEN=		Qt5 requires Openssl 1.1.1, upgrade to FreeBSD 12.x/13.x or add DEFAULT_VERSIONS+=ssl=[openssl|libressl*] to /etc/make.conf
.endif

# LibreSSL does not currently support BIO_ADDR in DTLSv1_listen()
.if ${SSL_DEFAULT:Mlibressl*}
CONFIGURE_ARGS+=	-no-feature-dtls
.endif

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

.include <bsd.port.post.mk>
