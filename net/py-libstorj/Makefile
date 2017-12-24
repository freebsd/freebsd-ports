# $FreeBSD$

PORTNAME=	libstoraj
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Python bindings for libstorj

LICENSE=	LGPL21+

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libstorj.so:net/libstorj

USES=		localbase python:2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	Storj
GH_PROJECT=	python-libstorj
GH_TAGNAME=	b344699
GH_TUPLE=	Storj:libstorj:v1.0.2:libstorj

pre-build:
	@cd ${WRKSRC}; ${CP} -a ${WRKSRC_libstorj}/ ${WRKSRC}/ext/libstorj; \
	${LOCALBASE}/bin/swig3.0 -c++ -python -outdir lib/ext lib/ext/python_libstorj.i

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/ext/_python_libstorj.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_python_libstorj.so

.include <bsd.port.mk>
