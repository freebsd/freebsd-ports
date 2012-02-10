# New ports collection makefile for:	py-psutil
# Date created:				04 May 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	psutil
PORTVERSION=	0.4.1
CATEGORIES=	sysutils python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A process utilities module for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
