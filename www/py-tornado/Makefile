# New ports collection makefile for:	tornado
# Date created:				2009-09-14
# Whom:					Guixing Bai<khsing.cn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tornado
PORTVERSION=	1.1
CATEGORIES=	www python
MASTER_SITES=	http://github.com/downloads/facebook/tornado/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	ASL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

FETCH_ARGS=	-pRr

.include <bsd.port.mk>
