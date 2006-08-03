# New ports collection makefile for: svmlight
# Date created:	    2006-07-18
# Whom:	    Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	svmlight
PORTVERSION=	6.01
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://kodiak.cs.cornell.edu/svm_light/current/
DISTNAME=	svm_light

PATCH_SITES=	http://search.cpan.org/src/KWILLIAMS/Algorithm-SVMLight-0.05/
PATCHFILES=	SVMLight.patch

MAINTAINER=	gslin@gslin.org
COMMENT=	An implementation of Support Vector Machines (SVMs) in C

RESTRICTED=	only for education and research

INSTALLS_SHLIB=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

post-build:
	${CC} ${CFLAGS} -shared -o ${WRKSRC}/libsvmlight.so.1 \
		${WRKSRC}/svm_common.o ${WRKSRC}/svm_hideo.o \
		${WRKSRC}/svm_learn.o

do-install:
	${MKDIR} ${PREFIX}/include/svmlight
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/svmlight
.for file in svm_classify svm_learn
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/libsvmlight.* ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libsvmlight.so.1 ${PREFIX}/lib/libsvmlight.so
# It's license request, do not remove
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}

post-install:
	@${CAT} ${WRKSRC}/LICENSE.txt

.include <bsd.port.mk>
