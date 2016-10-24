# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	artifacts
PORTVERSION=	20161022
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP \
		https://github.com/ForensicArtifacts/artifacts/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	ForensicArtifacts.com Artifact Repository

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
