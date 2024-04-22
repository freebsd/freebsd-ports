PORTNAME=	httptunnel
PORTVERSION=	3.3
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tunnel a TCP/IP connection through a HTTP/TCP/IP connection
WWW=		https://github.com/larsbrinkhoff/httptunnel/

LICENSE=	GPLv2

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	larsbrinkhoff
GH_PROJECT=	httptunnel
GH_TAGNAME=	ebe2583
USE_RC_SUBR=	hts htc

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--quiet

USERS=		httptunnel
GROUPS=		httptunnel

PLIST_FILES=	bin/hts bin/htc \
		share/man/man1/hts.1.gz share/man/man1/htc.1.gz

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug
.include <bsd.port.mk>
