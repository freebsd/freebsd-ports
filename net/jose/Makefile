PORTNAME=	jose
DISTVERSION=	11
CATEGORIES=	net

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tools for JSON Object Signing and Encryption (JOSE)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c11 meson ninja pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
GH_TAGNAME=	v11
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
