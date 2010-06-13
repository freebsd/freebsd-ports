# New ports collection makefile for:	progressbar
# Date created:		Wed Apr  7 13:54:04 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	progressbar
PORTVERSION=	2.2
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A text progressbar library for python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes

PLIST_FILES=	\
		%%PYTHON_SITELIBDIR%%/progressbar.py \
		%%PYTHON_SITELIBDIR%%/progressbar.pyc \
		%%PYTHON_SITELIBDIR%%/progressbar.pyo

post-patch:
	@${REINPLACE_CMD} -E -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
