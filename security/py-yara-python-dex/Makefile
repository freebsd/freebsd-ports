PORTNAME=	yara-python-dex
PORTVERSION=	1.0.9
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Prebuilt dex-enabled yara-python wheels
WWW=		https://github.com/MobSF/yara-python-dex

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	MobSF VirusTotal:yp VirusTotal:yp2
GH_PROJECT=	yara-python:yp yara:yp2
GH_TAGNAME=	188cb6e85137f715fef563f61c6b4f21ad026562:yp	\
		ed1a1a430c64cf908b61a5fadc3958866a840bc6:yp2
GH_SUBDIR=	yara-python:yp yara-python/yara:yp2

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}yara

USES=		pytest python ssl
USE_PYTHON=	distutils

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/yara%%PYTHON_TAG%%.so

.include <bsd.port.mk>
