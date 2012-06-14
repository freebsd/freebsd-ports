# New ports collection makefile for:	py-rsa
# Date created:		2012-05-24
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rsa
PORTVERSION=	3.0.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Pure-Python RSA implementation

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.0.13:${PORTSDIR}/devel/py-asn1

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PYDISTUTILS_INSTALLARGS=	-Z -q -O 1 -N -S ${PYTHON_SITELIBDIR} \
				-d ${PYEASYINSTALL_SITELIBDIR} \
				-s ${PYEASYINSTALL_BINDIR} \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}

.include <bsd.port.mk>
