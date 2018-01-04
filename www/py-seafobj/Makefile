# $FreeBSD$

PORTNAME=	seafobj
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAHUB_VER}
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Python library for accessing seafile data model

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:-2.7 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
USE_PYTHON=	flavors
SHEBANG_FILES=	*.sh *.py

NO_ARCH=	yes
NO_BUILD=	yes

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
