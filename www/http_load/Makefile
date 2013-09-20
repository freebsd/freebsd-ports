# Created by: Ask Bjoern Hansen <ask@valueclick.com>
# $FreeBSD$

PORTNAME=	http_load
PORTVERSION=	20060312
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/
DISTNAME=	${PORTNAME}-12mar2006

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprocessing http performance test client

MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN1=		http_load.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/http_load

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
