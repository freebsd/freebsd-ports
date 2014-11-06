# $FreeBSD$

PORTNAME=	seafdav
PORTVERSION=	3.0.4
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Python library for accessing seafile data model

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}WsgiDAV>=0.5:${PORTSDIR}/www/py-wsgidav

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v${PORTVERSION}-server-testing
GH_COMMIT=	42dfd99

USES=		python:2
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/wsgidav/addons/seafile
	(cd ${WRKSRC}/wsgidav/addons/seafile && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PYTHON_SITELIBDIR}/wsgidav/addons/seafile)
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${PYTHONPREFIX_SITELIBDIR} \
			-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${PYTHONPREFIX_SITELIBDIR} \
			-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
