PORTNAME=	iddawc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	OAuth2/OIDC Client and Relying Party library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yder>1.4.14:devel/yder \
		orcania>2.2.1:devel/orcania \
		gnutls>0:security/gnutls
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libgnutls.so:security/gnutls \
		liborcania.so:devel/orcania \
		libyder.so:devel/yder \
		libmicrohttpd.so:www/libmicrohttpd \
		librhonabwy.so:security/rhonabwy \
		libulfius.so:www/ulfius

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

CMAKE_ARGS=	-DWITH_JOURNALD=off

.include <bsd.port.mk>
