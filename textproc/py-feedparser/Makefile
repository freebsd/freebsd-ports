# ex:ts=8
# Ports collection makefile for:	feedparser
# Date created: 		Mar 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedparser
PORTVERSION=	2.76
CATEGORIES=	textproc python
MASTER_SITES=	http://diveintomark.org/projects/feed_parser/
EXTRACT_SUFX=	.py
DISTNAME=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS feed parser

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR:S,^${PREFIX}/,,}/${PORTNAME}.py

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
