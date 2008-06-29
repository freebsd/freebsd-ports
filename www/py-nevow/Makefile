# New ports collection makefile for:	py-nevow
# Date created:		2005-04-16
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	nevow
PORTVERSION=	0.9.18
PORTREVISION=	2
CATEGORIES=	www python devel
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Nevow-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web application templating system, based on the the Twisted Woven

BROKEN=		doesn't build: in nevow/static.py", line 18, twisted.web import error

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes
PYDISTUTILS_PKGNAME=	Nevow

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
			${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ">> Build documents ..."
	cd ${WRKSRC}/doc && ${PYTHON_CMD} make.py
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing documents to ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} . -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${WRKSRC}/examples')"

	@${ECHO_CMD} -n ">> Installing examples to ${EXAMPLESDIR}..."
	@cd ${WRKSRC}/examples && \
		${FIND} . -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
