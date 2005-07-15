# New ports collection makefile for:	http_load
# Date created:				9 May 2000
# Whom:					Ask Bjoern Hansen <ask@valueclick.com>
#
# $FreeBSD$
#

PORTNAME=	http_load
PORTVERSION=	20020104
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/
DISTNAME=	${PORTNAME}-04jan2002

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprocessing http performance test client

WRKSRC=		${WRKDIR}/http_load-04jan2002
MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN1=		http_load.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/http_load

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.else
PKGNAMESUFFIX=	-nossl
.endif

.include <bsd.port.mk>
