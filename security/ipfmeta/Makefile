# ex:ts=8
# New ports collection makefile for:	ipfmeta
# Date created:			Feb 22, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipfmeta
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	ipfmeta - use objects in IPfilter files

USE_PERL5=	yes

MAN1=	ipfmeta.1
POD2MAN?=	pod2man

do-build:
	@${POD2MAN} ${WRKSRC}/ipfmeta > ${WRKSRC}/${MAN1}

do-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/ipfmeta ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/ipfmeta
	${INSTALL_DATA} ${WRKSRC}/ipf.* ${PREFIX}/share/ipfmeta

.include <bsd.port.mk>
