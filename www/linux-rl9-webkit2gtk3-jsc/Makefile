PORTNAME=	webkit2gtk3-jsc
PORTVERSION=	2.54.0
DISTVERSIONSUFFIX=	-1.el9_8
CATEGORIES=	www linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	JavaScriptCore, the JavaScript engine of WebKitGTK (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://webkitgtk.org/

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	icu systemd-libs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

SRC_DISTFILES=	webkit2gtk3-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
