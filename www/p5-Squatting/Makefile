# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Squatting
PORTVERSION=	0.82
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BEPPU
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A Camping-inspired Web Microframework for Perl

COMMON_DEPENDS=	p5-Continuity>=0.991:${PORTSDIR}/www/p5-Continuity \
		p5-Class-C3-Componentised>0:${PORTSDIR}/devel/p5-Class-C3-Componentised \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Shell-Perl>0:${PORTSDIR}/shells/p5-Shell-Perl \
		p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Daemon>0:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-HTTP-Message>0:${PORTSDIR}/www/p5-HTTP-Message
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	squatting.1
MAN3=	\
	Squatting.3 \
	Squatting::Controller.3 \
	Squatting::H.3 \
	Squatting::Mapper.3 \
	Squatting::On::CGI.3 \
	Squatting::On::Catalyst.3 \
	Squatting::On::Continuity.3 \
	Squatting::On::MP13.3 \
	Squatting::On::MP20.3 \
	Squatting::View.3 \
	Squatting::With::AccessTrace.3 \
	Squatting::With::Coro::Debug.3 \
	Squatting::With::Log.3 \
	Squatting::With::MockRequest.3 \
	Squatting::With::Mount.3

.include <bsd.port.mk>
