# New ports collection makefile for:	p5-HTTP-Cache-Transparent
# Date created:		2005-10-14
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Cache-Transparent
PORTVERSION=	1.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of http get that keeps a local cache of fetched pages

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes
MAN3=		HTTP::Cache::Transparent.3

.include <bsd.port.mk>
