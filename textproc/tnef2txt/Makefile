# New ports collection makefile for:	tnef2txt
# Date created:			14 Jan 2002
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tnef2txt
PORTVERSION=	1.4
CATEGORIES=	textproc converters
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	jim@FreeBSD.org

ALL_TARGET=	tnef2txt

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/tnef2txt"
	@${MKDIR} ${PREFIX}/share/doc/tnef2txt && \
		${CHMOD} a+rx ${PREFIX}/share/doc/tnef2txt
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tnef2txt
.endif

.include <bsd.port.mk>
