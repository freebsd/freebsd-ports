# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zimpl
DISTVERSION=	3.3.4
CATEGORIES=	math
MASTER_SITES=	http://zimpl.zib.de/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language to translate the LP models into .lp or .mps

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=${CC} LINKCC=${CC} DCC=${CC} LDFLAGS="${LDFLAGS} -lgmp -lm -lz" SHARED=true

PLIST_FILES=	bin/zimpl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/zimpl-* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
