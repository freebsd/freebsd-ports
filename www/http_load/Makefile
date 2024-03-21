PORTNAME=	http_load
PORTVERSION=	20160309
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/
DISTNAME=	${PORTNAME}-09Mar2016

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	Multiprocessing http performance test client
WWW=		https://www.acme.com/software/http_load/

LICENSE=	BSD2CLAUSE

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_load \
		share/man/man1/http_load.1.gz

.ifndef NO_OPENSSL
USES+=	ssl
.endif

.include <bsd.port.mk>
