# $FreeBSD$

PORTNAME=	seafobj
PORTVERSION=	5.1.6
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Python library for accessing seafile data model

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

NO_ARCH=	yes
NO_BUILD=	yes
USES=		python:-2.7 shebangfix
SHEBANG_FILES=	*.sh *.py

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEAHUBDIR=	${SEAFILE_SERVER}/seahub
SITEPACKAGEDIR=	${SEAHUBDIR}/thirdpart

USERS=		seafile
GROUPS=		${USERS}

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		SEAHUBDIR=${SEAHUBDIR} \
		HAIWENDIR=${HAIWENDIR} \
		SITEPACKAGEDIR=${SITEPACKAGEDIR}

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

.include <bsd.port.mk>
