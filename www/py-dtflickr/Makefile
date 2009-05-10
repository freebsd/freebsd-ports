# New ports collection makefile for:	py-dtflickr
# Date created:				19 August 2008
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	dtflickr
PORTVERSION=	1.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Spiffy Flickr API library using JSON

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.7:${PORTSDIR}/devel/py-simplejson

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
