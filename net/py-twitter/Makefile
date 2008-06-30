# ex:ts=8
# Ports collection makefile for:	py-twitter
# Date created:			Apr 13, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A python wrapper around the Twitter API

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${BUILD_DEPENDS}

PROJECTHOST=	python-twitter
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_twitter

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Leaves egg file behind on deinstall
.endif

.include <bsd.port.post.mk>
