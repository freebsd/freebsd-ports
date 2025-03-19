PORTNAME=	tcpsplit
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://www.icir.org/mallman/software/tcpsplit/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Break a libpcap trace along TCP connection boundaries
WWW=		https://www.icir.org/mallman/software/tcpsplit/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

PLIST_FILES=	bin/tcpsplit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpsplit ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
