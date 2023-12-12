PORTNAME=	cminpack
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Solving nonlinear equations and nonlinear least squares problems
WWW=		http://devernay.free.fr/hacks/cminpack/

LICENSE_FILE=	${WRKSRC}/CopyrightMINPACK.txt

USES=		blaslapack:openblas cmake localbase

USE_GITHUB=	yes
GH_ACCOUNT=	devernay

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	USE_BLAS

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "*.[ch] testdata" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
