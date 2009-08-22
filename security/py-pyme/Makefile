# New ports collection makefile for:	security/py-pyme
# Date created:				28 December 2008
# Whom:					Johan van Selst <johans@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	pyme
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johans@stack.nl
COMMENT=	Python interface to GPGME library

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme

USE_GMAKE=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=pygpgme

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,gpgme-config,${PREFIX}/bin/&,' \
		${WRKSRC}/Makefile ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,include/,&gpgme/,' ${WRKSRC}/Makefile

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} build)

.include <bsd.port.post.mk>
