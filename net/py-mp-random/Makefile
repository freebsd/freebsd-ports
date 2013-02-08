# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	mp-random
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	net python
MASTER_SITES=	http://mirrorproject.com/widget/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MirrorProjectRandomImageWidget-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display random Mirror Project images on your desktop

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

USE_PYTHON=	yes
USE_WX=		2.4
WX_COMPS=	python
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
