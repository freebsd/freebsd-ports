# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Feersum
PORTVERSION=	1.400
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STASH
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A PSGI engine for Perl based on EV/libev

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-EV>=4.0:${PORTSDIR}/devel/p5-EV \
		p5-Plack>=0.9950:${PORTSDIR}/www/p5-Plack
RUN_DEPENDS=	p5-EV>=4.0:${PORTSDIR}/devel/p5-EV \
		p5-Plack>=0.9950:${PORTSDIR}/www/p5-Plack
TEST_DEPENDS=	p5-AnyEvent>=5.26.1:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Guard>=1.012:${PORTSDIR}/devel/p5-Guard \
		p5-JSON-XS>=2:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-LeakTrace>=0.13:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-Test-TCP>=1.12:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

MAN1=		feersum.1
MAN3=		Feersum.3 \
		Feersum::Connection.3 \
		Feersum::Connection::Handle.3 \
		Feersum::Runner.3 \
		Plack::Handler::Feersum.3

NO_STAGE=	yes
.include <bsd.port.mk>
