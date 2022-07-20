PORTNAME=	gotthard
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ssh through https proxy tunnel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotthard ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gotthard.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/gotthard.conf ${STAGEDIR}${PREFIX}/etc/gotthard.conf.sample

.include <bsd.port.mk>
