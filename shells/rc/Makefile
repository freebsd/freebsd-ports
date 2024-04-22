PORTNAME=	rc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
PORTREVISION=	5
CATEGORIES=	shells plan9

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Unix incarnation of the plan9 shell
WWW=		https://github.com/rakitzis/rc

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe
USE_GITHUB=	yes
GH_ACCOUNT=	rakitzis
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-history

OPTIONS_DEFINE=	READLINE

READLINE_USES=		readline
READLINE_CONFIGURE_ON=	--with-edit=readline
READLINE_MAKE_ARGS_OFF=	CFLAGS="${CFLAGS} -static"

.include <bsd.port.mk>
