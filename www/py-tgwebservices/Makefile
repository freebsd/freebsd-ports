# New ports collection makefile for:	py-tgwebservices
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgwebservices
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/T/${PYTGWEBSERVICES}/ \
		LOCAL/nivit/${PYTGWEBSERVICES}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTGWEBSERVICES}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multiprotocol Web Services for TurboGears

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.3.6:${PORTSDIR}/textproc/py-genshi
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYTGWEBSERVICES_EGG=${PYTGWEBSERVICES_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYTGWEBSERVICES=	TGWebServices
PYTGWEBSERVICES_EGG=	${PYTGWEBSERVICES}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
