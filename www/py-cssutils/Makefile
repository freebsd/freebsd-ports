# ex:ts=8
# Ports collection makefile for:	py-cssutils
# Date created:			Aug 26, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cssutils
PORTVERSION=	0.8a6
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://cthedot.de/cssutils/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CSS Cascading Style Sheets library for Python

RUN_DEPENDS=	${PYXML}

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,\((.\)examples\(.\),\1${EXAMPLESDIR:S,${PREFIX}/,,}\2,' \
	-e '/.*LICENSE.*/d' ${WRKSRC}/setup.py
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 0644

.include <bsd.port.mk>
