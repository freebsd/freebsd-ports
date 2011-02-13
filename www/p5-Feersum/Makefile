# New ports collection makefile for:	Feersum
# Date created:				2010-12-20
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Feersum
PORTVERSION=	1.001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STASH
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	A PSGI engine for Perl based on EV/libev

RUN_DEPENDS=	p5-Plack>=0.9950:${PORTSDIR}/www/p5-Plack \
		p5-EV>=4.0:${PORTSDIR}/devel/p5-EV \
		p5-AnyEvent>=5.261:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Guard>=1.012:${PORTSDIR}/devel/p5-Guard \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-TCP>=1.06:${PORTSDIR}/devel/p5-Test-TCP
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	feersum.1
MAN3=	Plack::Handler::Feersum.3 Feersum.3 Feersum::Runner.3 \
	Feersum::Connection.3 Feersum::Connection::Handle.3

.include <bsd.port.mk>
