# New ports collection makefile for:	py-oauthlib
# Date created:		2012-05-23
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oauthlib
PORTVERSION=	0.1.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	An RFC-compliant Python implementation of OAuth

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rsa>=0:${PORTSDIR}/security/py-rsa

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PYDISTUTILS_INSTALLARGS=	-Z -q -O 1 -N -S ${PYTHON_SITELIBDIR} \
				-d ${PYEASYINSTALL_SITELIBDIR} \
				-s ${PYEASYINSTALL_BINDIR} \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}

.include <bsd.port.mk>
