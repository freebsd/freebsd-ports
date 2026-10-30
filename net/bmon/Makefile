PORTNAME=	bmon
PORTVERSION=	5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Human-readable bandwidth monitor and rate estimator
WWW=		https://github.com/tgraf/bmon

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		autoreconf gettext-runtime:lib ncurses pkgconfig:build
USE_GITHUB=	yes
GH_ACCOUNT=	tgraf

GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools:build
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
