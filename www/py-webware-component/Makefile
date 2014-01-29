# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	Component
PORTVERSION=	0.2
CATEGORIES=	www python
MASTER_SITES=	http://www.webwareforpython.org/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}webware-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webware servlet component extension

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webware>0:${PORTSDIR}/www/py-webware

USE_PYTHON=	2

NO_STAGE=	yes
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
