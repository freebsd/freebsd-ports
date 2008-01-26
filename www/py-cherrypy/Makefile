# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.0.2
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	CherryPy

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'

.if defined(NOPORTEXAMPLES)
MAKE_ENV+=	NOPORTEXAMPLES=${NOPORTEXAMPLES}
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	 NOPORTDOCS=${NOPORTDOCS}
.endif

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
