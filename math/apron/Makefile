PORTNAME=	apron
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.13
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	APRON numerical abstract domain library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	ld: error: ../apron/libapron_debug.so: undefined reference to fpsetround

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
