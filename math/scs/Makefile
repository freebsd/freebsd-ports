# $FreeBSD$

PORTNAME=	scs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2-41
DISTVERSIONSUFFIX=	-gafc6a0b
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver of convex cone problems via operator splitting

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake blaslapack:openblas fortran # fortran is for openblas
USE_GITHUB=	yes
GH_ACCOUNT=	cvxgrp
USE_LDCONFIG=	yes

MAKE_ARGS=	BLASLDFLAGS="-lopenblas"

ALL_TARGET=	out/libscsdir.so out/libscsindir.so

HEADERS=	aa.h cones.h ctrlc.h glbopts.h linalg.h linsys.h normalize.h rw.h scs.h scs_blas.h util.h

PLIST_FILES=	${ALL_TARGET:S/out/lib/} ${HEADERS:S/^/include\/${PORTNAME}\//}

do-install:
.for so in ${ALL_TARGET}
	${INSTALL_LIB} ${WRKSRC}/${so} ${STAGEDIR}${PREFIX}/lib
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for h in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/${h} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor

.include <bsd.port.mk>
