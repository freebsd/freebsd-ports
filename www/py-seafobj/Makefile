# $FreeBSD$

PORTNAME=	seafobj
PORTVERSION=	${SEAHUB_VER}
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Python library for accessing seafile data model

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

NO_ARCH=	yes
NO_BUILD=	yes
USES=		python:-2.7 shebangfix
SHEBANG_FILES=	*.sh *.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITEPACKAGEDIR}/seafobj
	(cd ${WRKSRC}/seafobj && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC}/seafobj \
			-f ${WRKSRC}/seafobj && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC}/seafobj \
			-f ${WRKSRC}/seafobj)
	(cd ${WRKSRC}/seafobj && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITEPACKAGEDIR}/seafobj)

.include "${.CURDIR}/../../net-mgmt/seafile-server/Makefile.include"

.include <bsd.port.mk>
