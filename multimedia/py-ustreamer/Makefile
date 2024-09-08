PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	6.15
CATEGORIES=	multimedia net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and fast MJPG-HTTP streamer
WWW=		https://github.com/pikvm/ustreamer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libevent.so:devel/libevent

USES=		compiler:c17 gmake jpeg localbase:ldflags pkgconfig python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	pikvm

WRKSRC_SUBDIR=	python

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ustreamer${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
