PORTNAME=	apron
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.15
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	APRON numerical abstract domain library
WWW=		http://apron.cri.ensmp.fr/library/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libppl.so:devel/ppl

USES=		gmake localbase:ldflags
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	antoinemine

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${STAGEDIR}${PREFIX} -no-ocaml -no-java

post-stage:
	  @${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/lib*.so

.include <bsd.port.mk>
