PORTNAME=	fann
DISTVERSION=	2.2.0-20230126
CATEGORIES=	math science

MAINTAINER=	tzhuan@csie.org
COMMENT=	Free open source neural network library
WWW=		https://leenissen.dk/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libfann
GH_TAGNAME=	8409b42

.if !exists(/usr/include/omp.h)
PLIST_SUB=	OPENMP="@comment "
.else
PLIST_SUB=	OPENMP=""
.endif

.include <bsd.port.mk>
