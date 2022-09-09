PORTNAME=	yaph
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Proxy Hunter (proxy scanner)
WWW=		http://proxylabs.netwu.com/yaph/index.html

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaph/yaph ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yaph/yaph.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
