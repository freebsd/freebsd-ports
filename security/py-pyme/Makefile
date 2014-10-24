# Created by: Johan van Selst <johans@stack.nl>
# $FreeBSD$

PORTNAME=	pyme
PORTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Python interface to GPGME library

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme

USES=		gmake python:2
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=pygpgme

MAKE_ARGS=	PYTHON=${PYTHON_CMD}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,gpgme-config,${PREFIX}/bin/&,' \
		${WRKSRC}/Makefile ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,include/,&gpgme/,' ${WRKSRC}/Makefile

pre-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} build

.include <bsd.port.post.mk>
