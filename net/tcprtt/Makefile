# $FreeBSD$

PORTNAME=	tcprtt
DISTVERSION=	g20191022
CATEGORIES=	net

MAINTAINER=	rs@netflix.com
COMMENT=	Measures the TCP handshake RTT using the stats(9) statistics framework

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	KlaraSystems
GH_TAGNAME=	1c857b8bd6e071290d118c96c051fbdf7db40129

PLIST_FILES=	bin/tcprtt man/man8/${PORTNAME}.8.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300062
IGNORE=		requires kernel OSVERSION 1300062 or above
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcprtt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcprtt.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
