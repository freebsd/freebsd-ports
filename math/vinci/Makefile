PORTNAME=	vinci
DISTVERSION=	1.0.5
CATEGORIES=	math
MASTER_SITES=	https://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package that implements algorithms for convex body volume computation
WWW=		https://www.multiprecision.org/vinci/index.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

MAKEFILE=	makefile
MAKE_ARGS=	CC=${CC} OPT="${CFLAGS}"

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
