# New ports collection makefile for:   meld3
# Date created:        14 June 2009
# Whom:                Kirill P. Spitsin <tn@0x746e.org.ua>
#
# $FreeBSD$
#

PORTNAME=	meld3
PORTVERSION=	0.6.5
CATEGORIES=	www
MASTER_SITES=	http://www.plope.com/software/meld3/ \
				http://0x746e.org.ua/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tn@0x746e.org.ua
COMMENT=	HTML/XML templating system for Python 2.3+

RUN_DEPENDS=	py*-elementtree>=1.2:${PORTSDIR}/devel/py-elementtree

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
