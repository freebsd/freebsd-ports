# ex:ts=8
# New ports collection makefile for:	align
# Date created:			Oct 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	align
PORTVERSION=	1.7.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.indiana.edu/~kinzler/align/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text column alignment filter

USE_PERL5=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/bin|${PREFIX}/bin|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/*

.include <bsd.port.mk>
