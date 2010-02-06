# New ports collection makefile for:	supervisor
# Date created:		30 Dec, 2009
# Whom:			Hizbulin Ildar <hizel@vyborg.ru>
#
# $FreeBSD$
#

PORTNAME=	supervisor
PORTVERSION=	3.0a7
CATEGORIES=	sysutils python
MASTER_SITES=	http://dist.supervisord.org/\
	        CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System to monitor and control a number of processes on UNIX-like OS

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elementtree>=1.2.6:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_PKGNAMEPREFIX}meld3>=0.6.4:${PORTSDIR}/www/py-meld3 \
		${PYTHON_PKGNAMEPREFIX}medusa>=0.5.4:${PORTSDIR}/net/py-medusa

.include <bsd.port.mk>
