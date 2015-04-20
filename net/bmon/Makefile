# Created by: Jon Nistor <nistor@snickers.org>
# $FreeBSD$

PORTNAME=	bmon
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	michelle@sorbs.net
COMMENT=	Human-readable bandwidth monitor and rate estimator

LICENSE=	MIT

LIB_DEPENDS=	libconfuse.so:${PORTSDIR}/devel/libconfuse

CONFLICTS_INSTALL=	bmon-*

USE_GITHUB=	yes
GH_ACCOUNT=	tgraf
GH_COMMIT=	ad62e66
GH_TAGNAME=	v${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf ncurses pkgconfig:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
