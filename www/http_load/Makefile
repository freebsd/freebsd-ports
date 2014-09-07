# Created by: Ask Bjoern Hansen <ask@valueclick.com>
# $FreeBSD$

PORTNAME=	http_load
PORTVERSION=	20060312
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/
DISTNAME=	${PORTNAME}-12mar2006

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprocessing http performance test client

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_load \
		man/man1/http_load.1.gz

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

.include <bsd.port.mk>
