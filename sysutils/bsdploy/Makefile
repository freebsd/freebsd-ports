# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdploy
DISTVERSION=	1.0b4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Container Management for FreeBSD Jails

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}liblzma>0:${PORTSDIR}/archivers/py-liblzma \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.0.r13:${PORTSDIR}/sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}ploy_ansible>=1.0.b7:${PORTSDIR}/sysutils/py-ploy_ansible \
		${PYTHON_PKGNAMEPREFIX}ploy_ezjail>=1.0.b9:${PORTSDIR}/sysutils/py-ploy_ezjail \
		${PYTHON_PKGNAMEPREFIX}ploy_fabric>=1.0.b5:${PORTSDIR}/sysutils/py-ploy_fabric

OPTIONS_DEFINE=		EC2
OPTIONS_DEFAULT=	EC2
EC2_DESC=		Support Amazon Web Services EC2 hosts
EC2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy_ec2>0:${PORTSDIR}/sysutils/py-ploy_ec2

USES=			zip
USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
