# $FreeBSD$

PORTNAME=	seafdav
PORTVERSION=	${SEAHUB_VER}
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Python library for accessing seafile data model

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		python:-2.7 shebangfix
SHEBANG_FILES=	*.sh *.template wsgidav/addons/seafile/*.py
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITEPACKAGEDIR}/wsgidav
	(cd ${WRKSRC}/wsgidav && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC}/wsgidav \
			-f ${WRKSRC}/wsgidav && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC}/wsgidav \
			-f ${WRKSRC}/wsgidav)
	(cd ${WRKSRC}/wsgidav && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITEPACKAGEDIR}/wsgidav)

.include "${.CURDIR}/../../net-mgmt/seafile-server/Makefile.include"

.include <bsd.port.mk>
