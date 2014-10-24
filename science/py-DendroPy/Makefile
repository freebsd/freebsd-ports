# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	DendroPy
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Phylogenetic computing library

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
