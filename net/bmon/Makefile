PORTNAME=	bmon
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	michelle@sorbs.net
COMMENT=	Human-readable bandwidth monitor and rate estimator

LICENSE=	MIT

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USE_GITHUB=	yes
GH_ACCOUNT=	tgraf

GNU_CONFIGURE=	yes
USES=		autoreconf ncurses pkgconfig:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
