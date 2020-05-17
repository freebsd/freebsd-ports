# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	munkres
PORTVERSION=	1.0.12
DISTVERSIONPREFIX=	release-
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	10

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Munkres implementation for Python

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# munkres 1.1.1+ requires Python 3.5+
PORTSCOUT=	limit:^1\.0\.

GH_ACCOUNT=	bmc
USE_GITHUB=	yes

.include <bsd.port.mk>
