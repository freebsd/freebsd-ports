# ex:ts=8
# Ports collection makefile for:	feedparser
# Date created: 		Mar 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedparser
PORTVERSION=	3.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	feedparser
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS feed parser written in Python

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PYTHON=	yes
USE_ZIP=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR:S,^${PREFIX}/,,}/${PORTNAME}.py

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
