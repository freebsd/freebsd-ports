# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	psutil
PORTVERSION=	1.2.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Process utilities module for Python

LICENSE=	BSD3CLAUSE

PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}
USE_PYDISTUTILS=yes
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
