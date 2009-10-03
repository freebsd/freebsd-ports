# New ports collection makefile for:	tornado
# Date created:				2009-09-14
# Whom:					Guixing Bai<khsing.cn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tornado
PORTVERSION=	0.1
CATEGORIES=	www python
MASTER_SITES=	http://www.tornadoweb.org/static/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
