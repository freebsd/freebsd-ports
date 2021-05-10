PORTNAME=	tang
DISTVERSION=	10
CATEGORIES=	security

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tang is a small daemon for binding data to the presence of a network

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libjansson.so:devel/jansson \
		libjose.so:net/jose
RUN_DEPENDS=	socat:net/socat
BUILD_DEPENDS=	a2x:textproc/asciidoc \
		${LOCALBASE}/libdata/pkgconfig/jose.pc:net/jose \
		socat:net/socat

USES=		compiler:c11 meson ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
GH_TAGNAME=	v10
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

post-install:
	${MKDIR} -m 0700 ${STAGEDIR}/var/db/tang

.include <bsd.port.mk>
