# Created by: erich@rrnet.com

PORTNAME=	rc
PORTVERSION=	1.7.4
PORTREVISION=	3
DISTVERSIONPREFIX=v
CATEGORIES=	shells plan9

MAINTAINER=	quanstro@quanstro.net
COMMENT=	Unix incarnation of the plan9 shell

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe
USE_GITHUB=	yes
GH_ACCOUNT=	rakitzis
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-history

OPTIONS_DEFINE=	READLINE

READLINE_USES=		readline
READLINE_CONFIGURE_ON=	--with-edit=readline
READLINE_MAKE_ARGS_OFF=	CFLAGS="${CFLAGS} -static"

.include <bsd.port.mk>
