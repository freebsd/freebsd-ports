PORTNAME=	svmlight
PORTVERSION=	6.02
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://osmot.cs.cornell.edu/svm_light/v${PORTVERSION}/
DISTNAME=	svm_light

PATCH_SITES=	http://cpansearch.perl.org/src/KWILLIAMS/Algorithm-SVMLight-0.09/
PATCHFILES=	SVMLight.patch
PATCH_DIST_STRIP=-p1

LICENSE=	SVM-Light
LICENSE_NAME=	SVM-Light license
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Support Vector Machines (SVMs) in C

CFLAGS+=	-fPIC -fcommon
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes
USES=		gmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/svmlight
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/svmlight
.for file in svm_classify svm_learn
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/libsvmlight.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB}  ${WRKSRC}/libsvmlight.so ${STAGEDIR}${PREFIX}/lib/libsvmlight.so.1
	${LN} -s libsvmlight.so.1 ${STAGEDIR}${PREFIX}/lib/libsvmlight.so

.include <bsd.port.mk>
