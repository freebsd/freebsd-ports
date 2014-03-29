# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	novaclient
PORTVERSION=	2.6.8
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Client for the OpenStack Nova API

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:${PORTSDIR}/devel/py-prettytable \
		${PKGNAMEPREFIX}httplib2>=0:${PORTSDIR}/www/py-httplib2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
