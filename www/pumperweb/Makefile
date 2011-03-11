# New ports collection makefile for:	pumperweb
# Date created:		2007-03-28
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	pumperweb
PORTVERSION=	0.1
CATEGORIES=	www devel
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A meta project that creates a WEB framework

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ez_web/ez_user_auth.py:${PORTSDIR}/www/py-ez_web \
		${PYTHON_SITELIBDIR}/sqlcc/__init__.py:${PORTSDIR}/devel/py-sqlcc

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:

.include <bsd.port.mk>
