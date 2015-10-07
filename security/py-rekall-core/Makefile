# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall-core
PORTVERSION=	1.4.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	CORE component of the Rekall framework

LICENSE=	GPLv2

RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		${PYTHON_PKGNAMEPREFIX}acora>=1.8:${PORTSDIR}/textproc/py-acora \
		${PYTHON_PKGNAMEPREFIX}PyAFF4>=0.17:${PORTSDIR}/security/py-pyaff4 \
		${PYTHON_PKGNAMEPREFIX}capstone>=0:${PORTSDIR}/devel/py-capstone \
		${PYTHON_PKGNAMEPREFIX}distorm>=0:${PORTSDIR}/devel/py-distorm \
		${PYTHON_PKGNAMEPREFIX}efilter>=1438631774:${PORTSDIR}/devel/py-efilter \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.0.4:${PORTSDIR}/devel/py-intervaltree \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.3.1:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0.22:${PORTSDIR}/devel/py-pyelftools \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}yaml>=2.10:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}yara>=0:${PORTSDIR}/security/py-yara

USES=		python:2
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} '/argparse/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
