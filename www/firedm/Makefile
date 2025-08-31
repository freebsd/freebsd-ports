PORTNAME=	firedm
PORTVERSION=	2022.2.5
PORTREVISION=	3
CATEGORIES=	www net python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical download manager for streaming websites
WWW=		https://github.com/firedm/FireDM

LICENSE=	GPLv3+

RUN_DEPENDS=	yt-dlp:www/yt-dlp \
		${PYTHON_PKGNAMEPREFIX}AwesomeTkinter>=2021.6.4:x11-toolkits/py-awesometkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils noflavors
USE_GITHUB=	yes
GH_PROJECT=	FireDM

.include <bsd.port.mk>
