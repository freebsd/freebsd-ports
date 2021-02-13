# $FreeBSD$

PORTNAME=	yt-dlp
DISTVERSION=	2021.02.09
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line program to download videos from youtube & other platforms

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zip:archivers/zip \
		pandoc:textproc/hs-pandoc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	distutils autoplist noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	pukkandan

MAKE_ARGS=	PYTHON=${PYTHON_CMD}

NO_ARCH=	yes

POST_PLIST=	fix-plist

pre-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

.include <bsd.port.mk>
