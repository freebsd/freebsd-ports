# Created by: Kris Moore <kris@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-firewall
PORTVERSION=	201706210906
CATEGORIES=	sysutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	Qt5 based firewall manager for FreeBSD

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtrueos-ui.so:sysutils/trueos-libqt5

WRKSRC_SUBDIR=	src

CONFLICTS=	pcbsd-utils-qt*

USE_QT5=	core gui network svg multimedia imageformats \
		buildtools_build x11extras concurrent
USES=		qmake

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-firewall
GH_TAGNAME=	0e8cea961c6e727300db2582ea0ab2b988a6d8ec

.include <bsd.port.mk>
