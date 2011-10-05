# New ports collection makefile for:	net/p5-Net-Appliance-Session
# Date created:				05 May 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Appliance-Session
PORTVERSION=	3.112.610
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run command-line sessions to network appliances

BUILD_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Net-CLI-Interact>=0:${PORTSDIR}/net/p5-Net-CLI-Interact
RUN_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Net-CLI-Interact>=0:${PORTSDIR}/net/p5-Net-CLI-Interact

PERL_CONFIGURE=	yes

MAN3=		Net::Appliance::Session.3 \
		Net::Appliance::Session::APIv2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
