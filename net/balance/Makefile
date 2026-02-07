PORTNAME=	balance
PORTVERSION=	3.57
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.inlab.net/wp-content/uploads/2018/05/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Simple but powerful generic TCP proxy with round robin features
WWW=		https://www.inlab.de/balance.html

LICENSE=	GPLv2

ALL_TARGET=	balance
USE_RC_SUBR=	balance

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|' \
	-e 's|^CC|CC?|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/balance ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
