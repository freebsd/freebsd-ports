# New ports collection makefile for:	py-webware-component
# Date created:		2005-03-25
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	Component
PORTVERSION=	0.1
CATEGORIES=	www python
MASTER_SITES=	http://www.webwareforpython.org/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}webware-

MAINTAINER=	whitekid@gmail.com
COMMENT=	Webware servlet component extension

RUN_DEPENDS=	${LOCALBASE}/share/webware/__init__.py:${PORTSDIR}/www/py-webware

USE_PYTHON=	yes

do-build:
	@${ECHO_MSG} -n ">> Compiling ..."
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${WRKSRC}')"
	@${ECHO_MSG} " [ DONE ]"

do-install:
	@${ECHO_CMD} -n ">> Installing ..."
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} "${PREFIX}/share/webware/${PORTNAME}/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/webware/${PORTNAME}/{}" \;
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
