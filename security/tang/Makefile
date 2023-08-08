PORTNAME=	tang
DISTVERSION=	14
CATEGORIES=	security
MASTER_SITES=	https://github.com/latchset/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	hdholm@alumni.iastate.edu
COMMENT=	Tang is a small daemon for binding data to the presence of a network
WWW=		https://github.com/latchset/tang

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libjansson.so:devel/jansson \
		libjose.so:net/jose
BUILD_DEPENDS=	a2x:textproc/asciidoc \
		${LOCALBASE}/libdata/pkgconfig/jose.pc:net/jose \
		socat:net/socat \
		curl:ftp/curl

USES=		compiler:c11 cpe meson pkgconfig tar:xz

CPE_VENDOR=	tang_project

post-install:
	${MKDIR} -m 0700 ${STAGEDIR}/var/db/tang

.include <bsd.port.mk>
