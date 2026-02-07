PORTNAME=	http_ping
PORTVERSION=	20160309
CATEGORIES=	net www
MASTER_SITES=	http://www.acme.com/software/${PORTNAME}/
DISTNAME=	${PORTNAME}_09Mar2016

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Measure HTTP Latency
WWW=		https://www.acme.com/software/http_ping/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
PLIST_FILES=	bin/http_ping share/man/man1/http_ping.1.gz

post-extract:
	cd ${WRKSRC} && ${SED} -e '/^\*\*/,/^\*\//p;d' < http_ping.c > LICENSE

.include <bsd.port.mk>
