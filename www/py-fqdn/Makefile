# Created by: James White <whitejv81@gmail.com>
# $FreeBSD$

PORTNAME=	fqdn
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	whitejv81@gmail.com
COMMENT=	RFC-compliant FQDN validation and manipulation for Python

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cached-property>=1.3.0:devel/py-cached-property@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
