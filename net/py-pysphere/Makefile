# Created by: olli hauer <ohauer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysphere
PORTVERSION=	0.1.7
CATEGORIES=	net python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Python API for interaction with the vSphere Web Services SDK

LICENSE=	BSD

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-patch:
	@${SED} -i '' -e 's/pysphere-0.1.5/pysphere-0.1.7/' \
		${WRKSRC}/setup.py \
		${WRKSRC}/PKG-INFO \
		${WRKSRC}/pysphere.egg-info/PKG-INFO

.include <bsd.port.mk>
