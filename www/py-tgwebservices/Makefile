# New ports collection makefile for:	py-tgwebservices
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgwebservices
PORTVERSION=	1.2.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		LOCAL/nivit/${PYTGWEBSERVICES}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TGWebServices-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multiprotocol Web Services for TurboGears

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.1.2:${PORTSDIR}/www/py-turbogears \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.3.6:${PORTSDIR}/textproc/py-genshi
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TGWebServices

.include <bsd.port.mk>
