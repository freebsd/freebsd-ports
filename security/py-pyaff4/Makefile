# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	PyAFF4
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python Advanced Forensic Format Version 4 library

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}intervaltree>=2.1.0:${PORTSDIR}/devel/py-intervaltree \
		${PYTHON_PKGNAMEPREFIX}python-snappy>=0:${PORTSDIR}/archivers/py-python-snappy \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.2.1:${PORTSDIR}/textproc/py-rdflib

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
