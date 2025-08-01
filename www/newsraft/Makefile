PORTNAME=	newsraft
DISTVERSION=	0.32
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/${PORTNAME}/${PORTNAME}/archive/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Feed reader for terminal
WWW=		https://codeberg.org/newsraft/newsraft

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/doc/license.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgumbo.so:devel/gumbo

USES=		pkgconfig sqlite

MAKEFILE=	makefile
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
TEST_ENV+=	LANG=C.UTF-8
TEST_TARGET=	check

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
