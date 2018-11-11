# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zimpl
DISTVERSION=	3.3.6
CATEGORIES=	math
MASTER_SITES=	https://zimpl.zib.de/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language to translate the LP models into .lp or .mps

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	missing make/make.linux.$${arch}.gnu.opt for other architectures

BUILD_DEPENDS=	bison:devel/bison
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=${CC} LINKCC=${CC} DCC=${CC} LDFLAGS="${LDFLAGS} -lgmp -lm -lz" SHARED=true

PLIST_FILES=	bin/zimpl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/zimpl-* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
