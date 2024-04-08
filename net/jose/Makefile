PORTNAME=	jose
DISTVERSION=	13
CATEGORIES=	net

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tools for JSON Object Signing and Encryption (JOSE)
WWW=		https://github.com/latchset/jose

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc \
                jq:textproc/jq
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c11 meson ninja pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
GH_TAGNAME=	v13
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
