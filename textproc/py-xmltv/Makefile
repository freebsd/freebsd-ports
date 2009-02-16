# New ports collection makefile for:	python xmltv
# Date created:		Sun May  8 21:31:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmltv
PORTVERSION=	1.3
CATEGORIES=	textproc python
MASTER_SITES=	http://www.funktronics.ca/python-xmltv/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-xmltv-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	A Python module that provides access to XMLTV TV listings

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-xmltv

.ifndef(NOPORTDOCS)
PORTDOCS=	README.txt
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
