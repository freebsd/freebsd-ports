# $FreeBSD$

PORTNAME=	igakit
DISTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Low-level routines for manipulations of NURBS geometries

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

BB_ACCOUNT=	dalcinl
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	9890376115e3

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

USES=		fortran python
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-shared # https://bitbucket.org/dalcinl/igakit/issues/3

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/igakit/igalib.so

.include <bsd.port.mk>
