# New ports collection makefile for:	mod_blowchunks
# Date created:				23 June 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_blowchunks
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
EXTRACT_SUFX=	.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rejecting and logging chunked requests

USE_APACHE=	yes
NO_WRKSUBDIR=	YES

APXSFLAGS=	-DTRUE=1 -DFALSE=0
.if !defined(WITHOUT_BLOWCHUNK_LOG)
APXSFLAGS+=	-DLOG_BLOWCHUNK
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
.if !defined(WITHOUT_BLOWCHUNK_LOG)
	@${ECHO_MSG} "================================================================================"
	@${ECHO_MSG} "If you do not want to log chunked requests, rebuild with WITHOUT_BLOWCHUNK_LOG"
	@${ECHO_MSG} "defined."
	@${ECHO_MSG} "================================================================================"
.endif
	cd ${WRKSRC} && ${MV} ${PKGNAME}.c ${PORTNAME}.c && \
	${APXS} ${APXSFLAGS} -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so
	@${ECHO_MSG} "================================================================================"
	@${ECHO_MSG} "Enable mod_blowchunks in Apache's config manually."
	@${ECHO_MSG} "================================================================================"

.include <bsd.port.mk>
