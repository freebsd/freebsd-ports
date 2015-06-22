# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	backports.ssl_match_hostname
PORTVERSION=	3.4.0.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backport of ssl.match_hostname() function

# PR 201050 - is a blocker for removal of this port
DEPRECATED=	Function match_hostname() is in standard library since Python 2.7.9
EXPIRATION_DATE=	2015-06-02

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
