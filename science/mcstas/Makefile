PORTNAME=	mcstas
PORTVERSION=	2.5
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/${PORTNAME}-${PORTVERSION}/unix/
DISTNAME=	mcstas-${PORTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Monte Carlo neutron ray tracing package

LICENSE=	GPLv2

USES=		bison:build cmake shebangfix

CMAKE_ARGS=	"-Denable_mcstas=1"
SHEBANG_FILES=	cmake/support/install-scripts/postinst.in cmake/support/run-scripts/mccode_errmsg.in
MANDIRS=	${PREFIX}/${PORTNAME}/${DISTVERSION}/doc/man/man1
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MCEXECS=	mcstas mcformat

post-install:
.for e in ${MCEXECS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/${e}
	${RLN} ${STAGEDIR}/${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
