PORTNAME=	jdupes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Powerful duplicate file finder and an enhanced fork of 'fdupes'
WWW=		https://github.com/jbruchon/jdupes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjodycode.so:devel/libjodycode \
		libxxhash.so:devel/xxhash

USES=		gmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	jbruchon

MAKE_FLAGS=	EXTERNAL_HASH_LIB=1
LDFLAGS+=	-ljodycode -lxxhash

PLIST_FILES=	bin/jdupes \
		man/man1/jdupes.1.gz

OPTIONS_DEFINE=		LOW_MEMORY
LOW_MEMORY_DESC=	Minimally-featured build for embedded systems
LOW_MEMORY_MAKE_ENV=	LOW_MEMORY=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
