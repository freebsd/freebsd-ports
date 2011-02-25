# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

.if !defined(NOPORTEXAMPLES)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	CherryPy

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${PYTHONPREFIX_SITELIBDIR}/cherrypy && ${COPYTREE_SHARE} tutorial ${EXAMPLESDIR}
.endif
	${RM} -R ${PYTHONPREFIX_SITELIBDIR}/cherrypy/tutorial

.include <bsd.port.mk>
