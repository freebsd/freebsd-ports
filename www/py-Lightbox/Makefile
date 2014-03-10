# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lightbox
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightbox photo display widget for TurboGears

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.1.2:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scriptaculous>=1.8.1:${PORTSDIR}/www/py-scriptaculous

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
