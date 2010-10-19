# Ports collection makefile for:	py-surl
# Date created:		2010-10-04
# Whom:			Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	surl
PORTVERSION=	0.7.0
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/37026875/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c-s@c-s.li
COMMENT=	URL shortening command line application

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson

LICENSE=	GPLv3

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USE_BZIP2=	yes

.include <bsd.port.mk>
