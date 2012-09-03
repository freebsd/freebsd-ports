# New ports collection makefile for:	py-pybeanstalk
# Date created:		2012-09-03
# Whom:			Marcelo Araujo <araujo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pybeanstalk
PORTVERSION=	0.11.1
CATEGORIES=	net python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A pure python client library for beanstalkd queue

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALL_EGGINFO=yes
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

WRKSRC=	${WRKDIR}/${PORTVERSION}

.include <bsd.port.mk>
