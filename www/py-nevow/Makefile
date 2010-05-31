# New ports collection makefile for:	py-nevow
# Date created:		2005-04-16
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	nevow
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	www python devel
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Nevow-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A web application templating system, based on the the Twisted Woven

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_TWISTED=	web
USE_GETTEXT=	yes
PYDISTUTILS_PKGNAME=	Nevow

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documents to ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTEXAMPLES)
	@${PYTHON_CMD} -m compileall -f '${WRKSRC}/examples'
	@${PYTHON_CMD} -O -m compileall -f '${WRKSRC}/examples'
	@${ECHO_CMD} -n ">> Installing examples to ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
