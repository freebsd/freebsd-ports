# New ports collection makefile for:	python xmltv
# Date created:		Sun May  8 21:31:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmltv
PORTVERSION=	0.5.21
CATEGORIES=	textproc python
MASTER_SITES=	http://www.funktronics.ca/python-xmltv/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-xmltv-${PORTVERSION}

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS=	${BUILD_DEPENDS}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Python module that provides access to XMLTV TV listings

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	README.txt

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
