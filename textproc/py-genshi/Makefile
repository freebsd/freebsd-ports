# New ports collection makefile for:	py-genshi
# Date created:		2007-01-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	Genshi
PORTVERSION=	0.5.1
PORTREVISION=	3
#PORTEPOCH=	0
CATEGORIES=	textproc www python
MASTER_SITES=	http://ftp.edgewall.com/pub/${PORTNAME:L}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME:L}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python toolkit for stream-based generation of output for the web

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHONPREFIX_SITELIBDIR}/site-packages  -d ${PYTHONPREFIX_SITELIBDIR} ${WRKSRC}/dist/${PYEASYINSTALL_EGG}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
