PORTNAME=	sakisafe
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	net

MAINTAINER=	teru-sama@riseup.net
COMMENT=	Client for many file-sharing websites
WWW=		https://github.com/rfc-2549/sakisafe

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libcurl.so:ftp/curl

USES=		localbase
USE_GITHUB=	yes
GH_ACCOUNT=	rfc-2549

CFLAGS+=	-fPIC

PLIST_FILES=	bin/sakisafecli \
		share/man/man1/sakisafecli.1.gz \
		share/man/man5/sakisafeclirc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sakisafecli/sakisafecli ${STAGEDIR}${PREFIX}/bin/sakisafecli
	${INSTALL_MAN} ${WRKSRC}/sakisafecli/sakisafecli.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/sakisafecli/sakisafeclirc.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
