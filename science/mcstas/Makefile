# $FreeBSD$

PORTNAME=	mcstas
DISTVERSION=	2.2a
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/${PORTNAME}-${DISTVERSION}/unix/McStas-${DISTVERSION}-UNIX-src/
DISTNAME=	mcstas-${DISTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Monte Carlo neutron ray tracing package

LICENSE=	LGPL21+

USES=		bison:build cmake:outsource
CMAKE_ARGS=	"-Denable_mcstas=1"

MANDIRS=	${PREFIX}/${PORTNAME}/${DISTVERSION}/doc/man/man1
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

MCEXECS=	mcstas mcformat

post-install:
.for e in ${MCEXECS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/${DISTVERSION}/bin/${e}
	${LN} -s ${PREFIX}/${PORTNAME}/${DISTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
