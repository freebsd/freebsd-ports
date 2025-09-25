PORTNAME=	datovka
DISTVERSION=	4.27.0
CATEGORIES=	mail
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/${DISTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt re-implementation of Datovka
WWW=		https://gitlab.nic.cz/datovka/datovka

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libglvnd>0:graphics/libglvnd
LIB_DEPENDS=	libdatovka.so:devel/libdatovka

USES=		compiler:c++17-lang gl pkgconfig qmake qt:6 ssl tar:xz
USE_GL=		opengl
USE_QT=		5compat base svg websockets

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/datovka

.include <bsd.port.mk>
