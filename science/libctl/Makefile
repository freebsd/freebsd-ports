# Created by: ijliao
# $FreeBSD$

PORTNAME=	libctl
PORTVERSION=	3.2.2
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	devel@stasyan.com
COMMENT=	Control Language Library

LICENSE=	GPLv2

LIB_DEPENDS=	libguile-2.0.so:lang/guile2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USES=		fortran libtool pkgconfig
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lm

BROKEN_sparc64=	does not build

OPTIONS_DEFINE=	NLOPT DOCS EXAMPLES
NLOPT_DESC=	Use NLopt, an external NonLinear OPTimizer

NLOPT_LIB_DEPENDS=	libnlopt.so:math/nlopt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libctl.so.5.0.2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libctlgeom.so.5.0.2
	@${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/.libs/example

.include <bsd.port.mk>
