PORTNAME=	apron
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.13
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	APRON numerical abstract domain library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	uses deprecated fpsetround(3) that isn't even defined on arm64, see https://github.com/antoinemine/apron/issues/47
BROKEN_armv6=	uses deprecated fpsetround(3) that isn't even defined on armv6, see https://github.com/antoinemine/apron/issues/47
BROKEN_armv7=	uses deprecated fpsetround(3) that isn't even defined on armv7, see https://github.com/antoinemine/apron/issues/47
BROKEN_riscv64=	uses deprecated fpsetround(3) that isn't even defined on riscv64, see https://github.com/antoinemine/apron/issues/47

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libppl.so:devel/ppl

USES=		gmake localbase:ldflags
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${STAGEDIR}${PREFIX} -no-ocaml -no-java

USE_GITHUB=	yes
GH_ACCOUNT=	antoinemine

post-stage:
	  @${STRIP_CMD} \
	  	${STAGEDIR}${LOCALBASE}/bin/* \
	  	${STAGEDIR}${LOCALBASE}/lib/lib*.so

.include <bsd.port.mk>
