PORTNAME=	jose
DISTVERSION=	14
CATEGORIES=	net
MASTER_SITES=	https://github.com/latchset/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tools for JSON Object Signing and Encryption (JOSE)
WWW=		https://github.com/latchset/jose

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	jq:textproc/jq
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c11 meson pkgconfig ssl tar:xz
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc
MANPAGES_MESON_ENABLED=	docs

.include <bsd.port.mk>
