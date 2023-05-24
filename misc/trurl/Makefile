PORTNAME=	trurl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.6
CATEGORIES=	misc www

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Command line tool for URL parsing and manipulation
WWW=		https://github.com/curl/trurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	curl

MAKE_ARGS=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/trurl \
		share/man/man1/trurl.1.gz

.include <bsd.port.mk>
