# Created by: Johan van Selst <johans@stack.nl>
# $FreeBSD$

PORTNAME=	pyme
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to GPGME library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig1.3:devel/swig13
LIB_DEPENDS=	libgpgme.so:security/gpgme

USES=		gmake python:2
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=pygpgme

MAKE_ARGS=	PYTHON=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} 's,gpgme-config,${LOCALBASE}/bin/&,' \
		${WRKSRC}/Makefile ${WRKSRC}/setup.py

pre-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} build

.include <bsd.port.mk>
