# New ports collection makefile for:    lapack++
# Date created:         5 May 2002
# Whom:                 NAKATA Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	lapack++
PORTVERSION=	1.1
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/lapack++/
DISTNAME=	Lapackpp1_1a
EXTRACT_SUFX=  .tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} lapack++.ps.gz lapackpp1_1.ps.gz \
		lapackppman1_1.ps.gz lapack++_install.ps.gz
.endif
DIST_SUBDIR=	lapack++
EXTRACT_ONLY=	Lapackpp1_1a.tgz

MAINTAINER=	maho@FreeBSD.org

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/Lapackpp1.1a

post-patch:
	@(cd ${WRKSRC} ; ${MV} makefile Makefile)

do-install:
.for i in libblas++ liblamatrix++ liblapack++
	${INSTALL_DATA} ${WRKSRC}/${i}.a ${PREFIX}/lib
.endfor
	@${MKDIR} ${PREFIX}/include/lapack++
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/lapack++
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++_install.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackpp1_1.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackppman1_1.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
