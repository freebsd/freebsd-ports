# New ports collection makefile for:	wikitools
# Date created:		2009-07-26
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wikitools
PORTVERSION=	1.0
#PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python package for interacting with a MediaWiki wiki

PROJECTHOST=	python-${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easyinstall

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 260
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
