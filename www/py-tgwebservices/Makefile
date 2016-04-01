# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tgwebservices
PORTVERSION=	1.2.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		LOCAL/nivit/${PYTGWEBSERVICES}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TGWebServices-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multiprotocol Web Services for TurboGears

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.1.2:www/py-turbogears \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.3.6:textproc/py-genshi
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
