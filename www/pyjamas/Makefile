# New ports collection makefile for:	pyjamas
# Date created:		2008-10-07
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyjamas
PORTVERSION=	0.5
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A port of Google Web Toolkit to Python

USE_PYTHON=	yes
# install/require some libraries in sys.prefix
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	Pyjamas

REINPLACE_ARGS=	-i '' -e 's,../../bin,${PREFIX}/bin,'

post-patch:
	${FIND} ${WRKSRC}/examples -type f -name "build.sh" -print0 | ${XARGS} -0 ${REINPLACE_CMD}

post-install:
.if !defined(NOPORTEXAMPLES)
	${MV} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/share/pyjamas/examples ${EXAMPLESDIR}
.endif	
	${MV} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/share/pyjamas ${DATADIR}
	${RMDIR} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/share

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/img
	cd ${WRKSRC}/doc && ${CP} *.html ${DOCSDIR} && ${CP} img/* ${DOCSDIR}/img
.endif

.include <bsd.port.mk>
