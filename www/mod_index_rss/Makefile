# ex:ts=8
# New ports collection makefile for:	mod_index_rss
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_index_rss
PORTVERSION=	0.10
CATEGORIES=	www
MASTER_SITES=	http://software.tangent.org/download/ \
		ftp://ftp.tangent.org/pub/apache/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to provides RSS output for directories

USE_APACHE=	yes

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_index_rss.c

do-install:
	${APXS} -i -A -n index_rss ${WRKSRC}/mod_index_rss.so

.include <bsd.port.mk>
