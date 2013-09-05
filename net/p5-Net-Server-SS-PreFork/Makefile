# New ports collection makefile for:	p5-Net-Server-SS-PreFork
# Date created:				2012-01-21
# Whom:					Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Server-SS-PreFork
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	A hot-deployable variant of Net::Server::PreFork

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-Server>0:${PORTSDIR}/net/p5-Net-Server \
		p5-Server-Starter>=0.02:${PORTSDIR}/net/p5-Server-Starter
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-HTTP-Server-Simple>0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Test-SharedFork>0:${PORTSDIR}/devel/p5-Test-SharedFork \
		p5-Test-TCP>=0.06:${PORTSDIR}/devel/p5-Test-TCP \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Server::SS::PreFork.3

.include <bsd.port.mk>
