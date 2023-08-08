PORTNAME=	jdupes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.3
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
LOW_MEMORY_DESC=	Minimally-featured build for embedded systems
LOW_MEMORY_MAKE_ENV=	LOW_MEMORY=1

.include <bsd.port.options.mk>

# ELF Tool Chain's strip breaks binary so use LLVM's for now
# To avoid hardcoded stripping use INSTALL_KLD instead of _BIN
.if ${PORT_OPTIONS:MLOW_MEMORY} && !defined(WITH_DEBUG)
STRIP_CMD=	/usr/bin/llvm-strip
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jdupes

.include <bsd.port.mk>
