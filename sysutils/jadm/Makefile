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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:${PORTSDIR}/devel/py-tabulate \
		${PYTHON_PKGNAMEPREFIX}ipaddress>=1.0.6:${PORTSDIR}/net/py-ipaddress
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:${PORTSDIR}/devel/py-tabulate \
		${PYTHON_PKGNAMEPREFIX}ipaddress>=1.0.6:${PORTSDIR}/net/py-ipaddress

USES=		python
USE_PYTHON=	distutils autoplist
PLIST_FILES=	man/man8/jadm.8.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 901000
IGNORE=		 freeBSD before 9.1 is not supported
.endif

pre-install:
	${CP} ${WRKSRC}/man8/jadm.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.post.mk>
