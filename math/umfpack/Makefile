# New ports collection makefile for:	UMFPACK
# Date created:		5 Nov 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	umfpack
PORTVERSION=	4.4
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/umfpack/v${PORTVERSION}/
DISTNAME=	UMFPACKv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unsymmetric-pattern MultiFrontal Package

BUILD_DEPENDS=	${LOCALBASE}/lib/libcblas.a:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/${DISTNAME}/UMFPACK
ALL_TARGET=	lib

post-extract:
	${CP}	${WRKDIR}/${DISTNAME}/AMD/Make/Make.linux	\
		${WRKDIR}/${DISTNAME}/AMD/Make/Make.freebsd

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Lib/libamd.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Lib/libumfpack.a ${PREFIX}/lib
.for mod in AMD UMFPACK
	@${MKDIR} ${PREFIX}/include/${mod}
	@for inc in `${LS} ${WRKSRC}/../${mod}/Include` ; do \
		${INSTALL_DATA} ${WRKSRC}/../${mod}/Include/$$inc ${PREFIX}/include/${mod}; \
	done
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Doc/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/Doc/*.pdf  ${DOCSDIR}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} --exclude tmp -C ${WRKSRC}/Demo -cf - . | \
		${TAR} -C ${EXAMPLESDIR} -xf -
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
