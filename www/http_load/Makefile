# Created by: Ask Bjoern Hansen <ask@valueclick.com>
# $FreeBSD$

PORTNAME=	http_load
PORTVERSION=	20140814
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/
DISTNAME=	${PORTNAME}-14aug2014

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprocessing http performance test client

LICENSE=	BSD2CLAUSE

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_load \
		man/man1/http_load.1.gz

.ifndef NO_OPENSSL
USES+=	ssl
.endif

.include <bsd.port.mk>
