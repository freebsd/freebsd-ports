# New ports collection makefile for:	p5-URI-Query
# Date created:		2011-09-23
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Query
PORTVERSION=	0.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	URI query string manipulation

BUILD_DEPENDS=	p5-URI>=1.31:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	p5-URI>=1.31:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

MAN3=		URI::Query.3

.include <bsd.port.mk>
