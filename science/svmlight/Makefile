PORTNAME=	svmlight
PORTVERSION=	6.02
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	https://osmot.cs.cornell.edu/svm_light/v${PORTVERSION}/
DISTNAME=	svm_light

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Implementation of Support Vector Machines (SVMs) in C
WWW=		https://svmlight.joachims.org/

LICENSE=	SVM-Light
LICENSE_NAME=	SVM-Light license
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	# none

DEPRECATED=	Unmaintained, last upstream release in 2008 and there are more modern alternatives
EXPIRATION_DATE=2024-04-14

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LFLAGS="${CFLAGS}"
ALL_TARGET=	all libsvmlight_hideo

CFLAGS+=	-fPIC -fcommon

NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/svmlight
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/svmlight
.for file in svm_classify svm_learn
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_LIB}  ${WRKSRC}/libsvmlight.so ${STAGEDIR}${PREFIX}/lib/libsvmlight.so

.include <bsd.port.mk>
