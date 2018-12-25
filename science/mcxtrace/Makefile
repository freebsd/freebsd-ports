# $FreeBSD$

PORTNAME=	mcxtrace
DISTVERSION=	1.2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	science
MASTER_SITES=	http://download.mcxtrace.org/${PORTNAME}-${DISTVERSION}/unix/mcxtrace-${DISTVERSION}-src/

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Monte Carlo X-ray tracing package

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/lib/LGPL

USES=		bison:build cmake

PLIST_SUB=	DISTVERSION=${DISTVERSION}

MXEXECS=	mcxtrace mxformat

post-install:
.for e in ${MXEXECS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/${DISTVERSION}/bin/${e}
	@${RLN} ${STAGEDIR}${PREFIX}/${PORTNAME}/${DISTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/mcxtrace/${DISTVERSION}/LGPL

.include <bsd.port.mk>
