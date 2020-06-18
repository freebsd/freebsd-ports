# Created by: Eric Turgeon <ericturgeon.bsd@gmail.org>
# $FreeBSD$

PORTNAME=	networkmgr
DISTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	FreeBSD/GhostBSD network conection manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		doas:security/doas

USES=		gnome python:3.4+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_GNOME=	gtk-update-icon-cache pygobject3
USE_PYTHON=	distutils noflavors
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
