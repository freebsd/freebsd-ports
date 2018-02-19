# $FreeBSD$

PORTNAME=	pydotorgtheme
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Theme that emulates the look of python.org

RUN_DEPENDS=	tracd:www/trac \
		trac-themeengine>=2.0:www/trac-themeengine

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
