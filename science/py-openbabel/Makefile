PORTNAME=	openbabel
DISTVERSION=	3.1.1.1
PORTREVISION=	1
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data
WWW=		https://openbabel.org/wiki/Main_Page

LICENSE=	GPLv2+

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		python
USE_PYTHON=	distutils autoplist

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e 's|binary_function|__binary_function|g' \
		${WRKSRC}/openbabel/openbabel-python.i
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openbabel/_openbabel${PYTHON_TAG}.so

.include <bsd.port.mk>
