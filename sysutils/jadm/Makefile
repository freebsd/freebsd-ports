# Created by: Nikolay Dachev <jadm@dachev.info>
# $FreeBSD$

PORTNAME=	jadm
PORTVERSION=	1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jadm@dachev.info
COMMENT=	FreeBSD jail framework with zfs, vnet and jail.conf support

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:security/py-paramiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:net/py-netifaces@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:devel/py-tabulate@${FLAVOR} \
		${PY_IPADDRESS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:security/py-paramiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:net/py-netifaces@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:devel/py-tabulate@${FLAVOR} \
		${PY_IPADDRESS}

USES=		python
USE_PYTHON=	distutils autoplist
PLIST_FILES=	man/man8/jadm.8.gz

pre-install:
	${INSTALL_MAN} ${WRKSRC}/man8/jadm.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
