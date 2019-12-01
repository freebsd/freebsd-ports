# $FreeBSD$

PORTNAME=	rclone-browser
DISTVERSION=	1.7.0
CATEGORIES=	net

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Simple cross platform GUI for rclone

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rclone:net/rclone

USES=		cmake pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	kapitainsky
GH_PROJECT=	RcloneBrowser
USE_QT=		buildtools_build core gui qmake_build widgets

.include <bsd.port.mk>
