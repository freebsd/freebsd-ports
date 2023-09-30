PORTNAME=	libctl
DISTVERSION=	4.5.0
PORTREVISION=	2
CATEGORIES=	science math
MASTER_SITES=	https://github.com/NanoComp/libctl/releases/download/v${DISTVERSION}/

MAINTAINER=	devel@stasyan.com
COMMENT=	Control Language Library
WWW=		https://libctl.readthedocs.io/en/latest/

LICENSE=	GPLv2

USES=		fortran guile:2.2 libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lm

OPTIONS_DEFINE=		NLOPT DOCS EXAMPLES
OPTIONS_DEFAULT=	NLOPT
NLOPT_DESC=		Use NLopt, an external NonLinear OPTimizer

NLOPT_LIB_DEPENDS=	libnlopt.so:math/nlopt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libctl.so.7.3.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libctlgeom.so.7.3.0
	@${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/.libs/example

.include <bsd.port.mk>
