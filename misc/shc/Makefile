# ex:ts=8
# New ports collection makefile for:	shc
# Date created:		Feb 14, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shc
PORTVERSION=	3.2
CATEGORIES=	misc
MASTER_SITES=	ftp://asterix.fi.upm.es/pub/facultad/departamentos/datsi/frosal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

ALL_TARGET=	shc

MAN1=	shc.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
