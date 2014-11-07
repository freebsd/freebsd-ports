# $FreeBSD$

PORTNAME=	seafobj
PORTVERSION=	3.0.4
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Python library for accessing seafile data model

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v${PORTVERSION}-server-testing
GH_COMMIT=	58a4346

NO_BUILD=	yes
USES=		python:2

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/seafobj
	(cd ${WRKSRC}/seafobj && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/seafobj)
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
