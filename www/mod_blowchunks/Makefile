# New ports collection makefile for:	mod_blowchunks
# Date created:				23 June 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_blowchunks
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
EXTRACT_SUFX=	.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rejecting and logging chunked requests

MAKE_JOBS_SAFE=  yes

OPTIONS=	BLOWCHUNK_LOG	"Log chunked requests"	off

USE_APACHE=	1.3
NO_WRKSUBDIR=	YES

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_EXTRAS=	-DTRUE=1 -DFALSE=0

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BLOWCHUNK_LOG)
AP_EXTRAS+=	-DLOG_BLOWCHUNK
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}${EXTRACT_SUFX}

.include <bsd.port.post.mk>
