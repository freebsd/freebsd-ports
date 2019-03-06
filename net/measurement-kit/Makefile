# $FreeBSD$

PORTNAME=		measurement-kit
DISTVERSIONPREFIX=	v
DISTVERSION=		0.9.3
CATEGORIES=		net devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Portable C++14 network measurement library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libmaxminddb.so:net/libmaxminddb
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		autoreconf:build compiler:c++14-lang libtool ssl
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libcurl=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-libmaxminddb=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

INSTALL_TARGET=	install-strip
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-configure:
	@(cd ${WRKSRC} && ${SH} autogen.sh --no-geoip && \
	  ${SETENV} ${CONFIGURE_ENV} ${SH} configure ${CONFIGURE_ARGS})

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/include/measurement_kit/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
