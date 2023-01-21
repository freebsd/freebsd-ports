PORTNAME=	jdupes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.1
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Powerful duplicate file finder and an enhanced fork of 'fdupes'
WWW=		https://github.com/jbruchon/jdupes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxxhash.so:devel/xxhash

USES=		gmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	jbruchon

LDFLAGS+=	-lxxhash

PLIST_FILES=	bin/jdupes \
		man/man1/jdupes.1.gz

OPTIONS_DEFINE=		LOW_MEMORY
LOW_MEMORY_DESC=	Build for lower memory usage instead of speed
LOW_MEMORY_MAKE_ENV=	LOW_MEMORY=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
