# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	turbomail
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	mail www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TurboMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multi-threaded mail queue manager for TurboGears applications

LICENSE=	MIT

BUILD_DEPENDS=	tg-admin:www/py-turbogears
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
