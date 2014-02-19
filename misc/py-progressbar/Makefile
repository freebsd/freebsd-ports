# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	progressbar
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text progressbar library for python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
