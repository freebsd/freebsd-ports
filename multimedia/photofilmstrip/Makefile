# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	photofilmstrip
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/photostoryx/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Creates movies out of your pictures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PY_PILLOW}
RUN_DEPENDS=	mencoder:multimedia/mencoder \
		mplayer:multimedia/mplayer

USES=		python:3.6+ gettext
USE_GSTREAMER1=	jpeg
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	python:lib
ALL_TARGET=	compile
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
