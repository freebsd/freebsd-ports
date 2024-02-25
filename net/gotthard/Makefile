PORTNAME=	gotthard
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ssh through https proxy tunnel
WWW=		http://www.nazgul.ch/dev.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotthard ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gotthard.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_DATA} ${WRKSRC}/gotthard.conf ${STAGEDIR}${PREFIX}/etc/gotthard.conf.sample

.include <bsd.port.mk>
