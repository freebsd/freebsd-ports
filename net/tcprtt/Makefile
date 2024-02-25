PORTNAME=	tcprtt
DISTVERSION=	g20191022
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	rs@netflix.com
COMMENT=	Measures the TCP handshake RTT using the stats(9) statistics framework

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	KlaraSystems
GH_TAGNAME=	1c857b8bd6e071290d118c96c051fbdf7db40129

PLIST_FILES=	bin/tcprtt share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcprtt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcprtt.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
