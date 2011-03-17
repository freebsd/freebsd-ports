# New ports collection makefile for:    Crypt::Random::Source
# Date created:                         15 March 2011
# Whom:                                 Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Random-Source
PORTVERSION=	0.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dereckson@gmail.com
COMMENT=	Get weak or strong random data from pluggable sources

TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>0:${PORTSDIR}/devel/p5-Test-use-ok
RUN_DEPENDS=	p5-Capture-Tiny>=0.08:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Module-Find>0:${PORTSDIR}/devel/p5-Module-Find \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean

MAN3=		Crypt::Random::Source.3 \
		Crypt::Random::Source::Base.3 \
		Crypt::Random::Source::Base::File.3 \
		Crypt::Random::Source::Base::Handle.3 \
		Crypt::Random::Source::Base::Proc.3 \
		Crypt::Random::Source::Base::RandomDevice.3 \
		Crypt::Random::Source::Factory.3 \
		Crypt::Random::Source::Strong.3 \
		Crypt::Random::Source::Strong::devrandom.3 \
		Crypt::Random::Source::Weak.3 \
		Crypt::Random::Source::Weak::devurandom.3 \
		Crypt::Random::Source::Weak::rand.3

PERL_CONFIGURE=	yes

LICENSE=	ART20

.include <bsd.port.mk>
