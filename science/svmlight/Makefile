# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	svmlight
PORTVERSION=	6.02
CATEGORIES=	science
MASTER_SITES=	http://osmot.cs.cornell.edu/svm_light/v${PORTVERSION}/
DISTNAME=	svm_light

PATCH_SITES=	http://cpansearch.perl.org/src/KWILLIAMS/Algorithm-SVMLight-0.09/
PATCHFILES=	SVMLight.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Support Vector Machines (SVMs) in C

RESTRICTED=	only for education and research

CFLAGS+=	-fPIC
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes
USES=		gmake
USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKSRC}/LICENSE.txt

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/svmlight
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/svmlight
.for file in svm_classify svm_learn
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/libsvmlight.* ${STAGEDIR}${PREFIX}/lib
	${MV} ${STAGEDIR}${PREFIX}/lib/libsvmlight.so ${STAGEDIR}${PREFIX}/lib/libsvmlight.so.1
	${LN} -s libsvmlight.so.1 ${STAGEDIR}${PREFIX}/lib/libsvmlight.so
# It's license request, do not remove
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
