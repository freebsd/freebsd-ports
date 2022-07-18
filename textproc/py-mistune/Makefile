# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	mistune
PORTVERSION=	2.0.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fastest markdown parser in pure Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

CPE_VENDOR=	mistune_project

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
