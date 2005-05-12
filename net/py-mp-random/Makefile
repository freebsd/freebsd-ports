# New ports collection makefile for: py-MirrorProjectRandomImageWidget
# Date created: 		     August 03, 2004
# Whom: Aaron Straup Cope 	     ascope@cpan.org
#
# $FreeBSD$
#

PORTNAME=mp-random
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://mirrorproject.com/widget/
PKGNAMEPREFIX=	py-
DISTNAME=	MirrorProjectRandomImageWidget-src-${PORTVERSION}

MAINTAINER=	randomimage-widget@mirrorproject.com
COMMENT=	Display random Mirror Project images on your desktop

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/wxc.so:${PORTSDIR}/x11-toolkits/py-wxPython24

USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

pre-install:
	${PRINTF} "#!${PYTHON_CMD}\n" > ${WRKSRC}/mp-random
	${CAT} ${WRKSRC}/MirrorProjectRandomImageWidget.py >> \
	       ${WRKSRC}/mp-random
	${CHMOD} 0755 ${WRKSRC}/mp-random

do-install:
	${ECHO} "Installing ${PREFIX}/bin/mp-random"
	${CP} ${WRKSRC}/mp-random ${PREFIX}/bin/

.include <bsd.port.mk>
