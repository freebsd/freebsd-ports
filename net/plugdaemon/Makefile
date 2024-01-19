PORTNAME=	plugdaemon
PORTVERSION=	2.5.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plug proxy daemon, forwards TCP/IP connections
WWW=		https://plugdaemon.sourceforge.net/

PLIST_FILES=	share/man/man1/plug.1.gz sbin/plug

do-install:
	${INSTALL_MAN} ${WRKSRC}/plug.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/plug ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
