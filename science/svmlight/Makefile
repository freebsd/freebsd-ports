# New ports collection makefile for: svmlight
# Date created:	    2006-07-18
# Whom:	    Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	svmlight
PORTVERSION=	6.02
CATEGORIES=	science
MASTER_SITES=	http://kodiak.cs.cornell.edu/svm_light/v${PORTVERSION}/
DISTNAME=	svm_light

PATCH_SITES=	http://cpansearch.perl.org/src/KWILLIAMS/Algorithm-SVMLight-0.09/
PATCHFILES=	SVMLight.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	gslin@gslin.org
COMMENT=	An implementation of Support Vector Machines (SVMs) in C

RESTRICTED=	only for education and research

CFLAGS+=	-fPIC
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

do-install:
	${MKDIR} ${PREFIX}/include/svmlight
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/svmlight
.for file in svm_classify svm_learn
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/libsvmlight.* ${PREFIX}/lib
	${MV} ${PREFIX}/lib/libsvmlight.so ${PREFIX}/lib/libsvmlight.so.1
	${LN} -s ${PREFIX}/lib/libsvmlight.so.1 ${PREFIX}/lib/libsvmlight.so
# It's license request, do not remove
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}

post-install:
	@${CAT} ${WRKSRC}/LICENSE.txt

.include <bsd.port.mk>
