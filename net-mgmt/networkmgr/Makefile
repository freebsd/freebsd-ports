# Created by: Eric Turgeon <ericturgeon.bsd@gmail.org>
# $FreeBSD$

PORTNAME=	networkmgr
PORTVERSION=	2.4
CATEGORIES=	net-mgmt

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	FreeBSD/GhostBSD network conection manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	doas:security/doas

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_ARCH=	yes
USES=		python:2.7 shebangfix
USE_PYTHON=	distutils
USE_GNOME=	pygtk2

SUB_FILES=	pkg-message

SHEBANG_FILES=	${WRKSRC}/src/*.py \
		${WRKSRC}/src/netcardmgr

.include <bsd.port.mk>
