# New ports collection makefile for:	tornado
# Date created:				2009-09-14
# Whom:					Guixing Bai<khsing.cn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tornado
PORTVERSION=	2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://github.com/downloads/facebook/tornado/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	ASL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install

FETCH_ARGS=	-pRr

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 260
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
