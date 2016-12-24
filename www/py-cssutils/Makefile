# Created by: ijliao
# $FreeBSD$

PORTNAME=	cssutils
PORTVERSION=	1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CSS Cascading Style Sheets library for Python

LICENSE=	LGPL3

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES?=		python zip

PORTEXAMPLES=	*

SLAVEDIRS=	www/py3-cssutils

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
