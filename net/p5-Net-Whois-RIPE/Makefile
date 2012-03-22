# ex:ts=8
# Ports collection makefile for:	p5-Net-Whois-RIPE
# Date created:			Sep 11, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	2.00003
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LMC
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

BUILD_DEPENDS=	p5-Iterator-Util>=0:${PORTSDIR}/devel/p5-Iterator-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=	Net::Whois::RIPE.3

.include <bsd.port.mk>
