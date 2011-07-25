# New ports collection makefile for:	 tvnamer
# Date created:		Mon Jul 25 02:11:57 UTC 2011
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	tvnamer
PORTVERSION=	2.1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Automatically names downloaded/recorded TV-episode

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}tvdb_api>=1.5:${PORTSDIR}/www/py-tvdb_api
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	\
		bin/${PORTNAME} \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
