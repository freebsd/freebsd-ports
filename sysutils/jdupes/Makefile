PORTNAME=	jdupes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.31.2
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/jbruchon/jdupes/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tom@hur.st
COMMENT=	Powerful duplicate file finder and an enhanced fork of 'fdupes'
WWW=		https://codeberg.org/jbruchon/jdupes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjodycode.so:devel/libjodycode \
		libxxhash.so:devel/xxhash

USES=		gmake localbase:ldflags

MAKE_FLAGS=	EXTERNAL_HASH_LIB=1
LDFLAGS+=	-ljodycode -lxxhash

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/jdupes \
		share/man/man1/jdupes.1.gz

OPTIONS_DEFINE=		LOW_MEMORY
LOW_MEMORY_DESC=	Minimally-featured build for embedded systems
LOW_MEMORY_MAKE_ENV=	LOW_MEMORY=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
