# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	qtfm
DISTVERSION=	6.1.7
CATEGORIES=	x11-fm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, lightweight file manager based on pure Qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		desktop-file-utils gl qmake qt:5
USE_GL=		gl
USE_QT=		concurrent core dbus gui widgets \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	rodlie

QMAKE_ARGS=	MANDIR=${MANDIRS} \
		PREFIX=${PREFIX} \
		XDGDIR=${PREFIX}/etc/xdg

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qtfm

.include <bsd.port.mk>
