# $FreeBSD$

PORTNAME=	mcstas
PORTVERSION=	2.2a
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/${PORTNAME}-${PORTVERSION}/unix/McStas-${PORTVERSION}-UNIX-src/
DISTNAME=	mcstas-${PORTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Monte Carlo neutron ray tracing package

LICENSE=	LGPL21+

USES=		bison:build cmake:outsource
CMAKE_ARGS=	"-Denable_mcstas=1"

MANDIRS=	${PREFIX}/${PORTNAME}/${DISTVERSION}/doc/man/man1
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MCEXECS=	mcstas mcformat

post-install:
.for e in ${MCEXECS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/${e}
	${LN} -s ${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
