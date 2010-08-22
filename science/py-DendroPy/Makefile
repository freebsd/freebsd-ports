# New ports collection makefile for:	py-DendroPy
# Date created:		09 Jan, 2010
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	DendroPy
PORTVERSION=	3.5.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phylogenetic computing library

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
