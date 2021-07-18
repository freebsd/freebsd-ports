# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	ip2proxy
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Varnish Module (vmod) for ip2proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libIP2Proxy.so:net/ip2proxy
BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=		autoreconf:build libtool pkgconfig python:build varnish:6
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
DOCSDIR=	${PREFIX}/share/doc/vmod-dynamic
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${WRKSRC}/src

USE_GITHUB=	yes
GH_ACCOUNT=	ip2location
GH_PROJECT=	${PORTNAME}-varnish

OPTIONS_DEFINE=	DOCS

pre-configure:
	(cd ${WRKSRC} && ${SH} ./autogen.sh)

.include <bsd.port.mk>
