# New ports collection makefile for:	pyblosxom
# Date created:		13 April 2005
# Whom:	      		Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	pyblosxom
DISTVERSION=	1.5.2
CATEGORIES=	www python
MASTER_SITES=	http://pyblosxom.bluesock.org/download/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	A lightweight weblog system

LICENSE=	MIT

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \. ${DOCSDIR}
.endif

.include <bsd.port.mk>
