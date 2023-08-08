PORTNAME=	jose
DISTVERSION=	11
CATEGORIES=	net

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tools for JSON Object Signing and Encryption (JOSE)
WWW=		https://github.com/latchset/jose

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c11 meson ninja pkgconfig ssl
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Fails to build with lots of ld: error: undefined symbol: EVP_CIPHER_*
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
GH_TAGNAME=	v11
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
