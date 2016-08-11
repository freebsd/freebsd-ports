# $FreeBSD$

PORTNAME=	themeengine
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-
DISTNAME=	TracThemeEngine-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to simplify distributing and deploying themes and styles

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

USES=		python:2 tar:bzip2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
