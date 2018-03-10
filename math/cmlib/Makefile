# Created by: Anton Shterenlikht <mexas@bris.ac.uk>
# $FreeBSD$

PORTNAME=	cmlib
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	NL/blas:blas ftp://ftp.nist.gov/pub/cmlib/
# Get d1mach.f, i1mach.f, r1mach.f from BLAS, rather than from CMLIB.
# See Netlib FAQ #2.17: http://netlib.org/misc/faq.html#2.17
DISTFILES=	src.tar.Z d1mach.f:blas i1mach.f:blas r1mach.f:blas
DIST_SUBDIR=	cmlib
EXTRACT_ONLY=	src.tar.Z

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	NIST Core math library (CMLIB)

USES=		fortran uidfix
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}
SHLIB_MAJOR=	1

LDFLAGS+=	${FFLAGS}
LDADD ?=	-lgfortran -lm
SRCCONF=	/dev/null
MAKE_ENV+=	LDADD="${LDADD}" SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF="${SRCCONF}"

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${_DISTDIR}/[dir]1mach.f ${WRKSRC}/src/machcon
	${CP} ${FILESDIR}/make.inc ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|../../src|src|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|../../utils|utils|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|testall :|testall : libcm|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|../../utils|utils|g' ${WRKSRC}/utils/Testall
	${REINPLACE_CMD} -e 's|../../test|test|g' ${WRKSRC}/utils/Testall
	${REINPLACE_CMD} -e 's|../../utils|utils|g' ${WRKSRC}/utils/Update
	${REINPLACE_CMD} -e 's|../../src|src|g' ${WRKSRC}/utils/Upar
	${REINPLACE_CMD} -e 's|../../utils|utils|g' ${WRKSRC}/utils/Upar

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcm.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
