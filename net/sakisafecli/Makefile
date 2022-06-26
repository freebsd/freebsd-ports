PORTNAME=	sakisafe
DISTVERSION=	2.2.1
CATEGORIES=	net
MASTER_SITES=	http://git.qorg11.net/sakisafe.git/snapshot/

MAINTAINER=	teru-sama@riseup.net
COMMENT=	Client for many file-sharing websites

LICENSE=	GPLv3

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libcurl.so:ftp/curl \
		libnghttp2.so:www/libnghttp2

USES=		localbase ssl

CFLAGS+=	-fPIC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sakisafecli/sakisafecli ${STAGEDIR}${PREFIX}/bin/sakisafecli
	${INSTALL_MAN} ${WRKSRC}/sakisafecli/sakisafecli.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sakisafecli/sakisafeclirc.5 ${STAGEDIR}${MAN1PREFIX}/man/man5

.include <bsd.port.mk>
