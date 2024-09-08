PORTNAME=	yices
DISTVERSION=	2.6.5
CATEGORIES=	math
MASTER_SITES=	https://yices.csl.sri.com/releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SMT solver
WWW=		https://yices.csl.sri.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gperf:devel/gperf
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf compiler:c11 gmake localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pic-gmp=${LOCALBASE}/lib/libgmp.so

MAKE_ARGS=	YICES_MAKE_INCLUDE=configs/make.include.${CONFIGURE_TARGET}
CFLAGS+=	-fPIC

TEST_TARGET=	test # tests fail to compile, see https://github.com/SRI-CSL/yices2/issues/523

WRKSRC=		${WRKDIR}/yices-${DISTVERSION}

post-install: # strip binaries
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
