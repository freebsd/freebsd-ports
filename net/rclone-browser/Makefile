# $FreeBSD$

PORTNAME=	rclone-browser
DISTVERSION=	1.2
CATEGORIES=	net

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Simple cross platform GUI for rclone

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rclone:net/rclone

USES=		cmake pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	mmozeiko
GH_PROJECT=	RcloneBrowser
USE_QT=		buildtools_build core gui qmake_build widgets

post-patch:
	${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' \
		${WRKSRC}/scripts/rclone-browser.desktop

.include <bsd.port.mk>
