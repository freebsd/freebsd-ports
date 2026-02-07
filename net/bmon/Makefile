PORTNAME=	bmon
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Human-readable bandwidth monitor and rate estimator
WWW=		https://github.com/tgraf/bmon

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.BSD
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		autoreconf gettext-runtime ncurses pkgconfig:build
USE_GITHUB=	yes
GH_ACCOUNT=	tgraf

GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
