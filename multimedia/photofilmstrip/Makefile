PORTNAME=	photofilmstrip
DISTVERSION=	3.7.1
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	https://github.com/PhotoFilmStrip/PFS/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates movies out of your pictures
WWW=		https://www.photofilmstrip.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PY_PILLOW}
RUN_DEPENDS=	mencoder:multimedia/mencoder \
		mplayer:multimedia/mplayer

USES=		python gettext gstreamer
USE_GSTREAMER=	jpeg
USE_PYTHON=	distutils
USE_WX=		3.2
WX_COMPS=	python:lib
ALL_TARGET=	compile
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
