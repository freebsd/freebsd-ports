# New ports collection makefile for:	py-bleach
# Date created:		2012-05-28
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bleach
PORTVERSION=	1.1.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	An easy whitelist-based HTML-sanitizing tool for Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.95:${PORTSDIR}/www/py-html5lib

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
