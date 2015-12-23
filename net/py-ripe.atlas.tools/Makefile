# Created by: Massimiliano Stucchi <mstucchi@ripe.net>
# $FreeBSD$

PORTNAME=	ripe.atlas.tools
PORTVERSION=	1.1.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mstucchi@ripe.net
COMMENT=	Official command-line client for RIPE Atlas

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}ripe.atlas.cousteau>=1.0.4:${PORTSDIR}/net/py-ripe.atlas.cousteau \
		${PYTHON_PKGNAMEPREFIX}ripe.atlas.sagan>=1.1.4:${PORTSDIR}/net/py-ripe.atlas.sagan \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:${PORTSDIR}/devel/py-tzlocal \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:${PORTSDIR}/security/py-openssl

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
