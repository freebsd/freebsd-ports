PORTNAME=	httptunnel
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tunnel a TCP/IP connection through a HTTP/TCP/IP connection

LICENSE=	GPLv2

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	larsbrinkhoff
GH_PROJECT=	httptunnel
GH_TAGNAME=	ebe2583
USE_RC_SUBR=	hts htc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet

USERS=		httptunnel
GROUPS=		httptunnel

PLIST_FILES=	bin/hts bin/htc \
		man/man1/hts.1.gz man/man1/htc.1.gz

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug
.include <bsd.port.mk>
