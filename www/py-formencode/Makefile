# New ports collection makefile for:	py-formencode
# Date created:		2005-11-16
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	formencode
PORTVERSION=	0.3
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/F/FormEncode/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormEncode-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	HTML form validation, generation, and conversion package

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESSDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
