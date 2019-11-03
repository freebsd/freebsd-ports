# Created by: Massimiliano Stucchi <mstucchi@ripe.net>
# $FreeBSD$

PORTNAME=	ripe.atlas.tools
PORTVERSION=	2.3.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mstucchi@ripe.net
COMMENT=	Official command-line client for RIPE Atlas

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ripe.atlas.cousteau>=1.0.4:net/py-ripe.atlas.cousteau@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ripe.atlas.sagan>=1.1.4:net/py-ripe.atlas.sagan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
