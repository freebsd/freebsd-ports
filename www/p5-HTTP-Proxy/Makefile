# Created by: mat
# $FreeBSD$

PORTNAME=	HTTP-Proxy
PORTVERSION=	0.300
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl HTTP proxy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTTP-Daemon>=1.25:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		\
		HTTP::Proxy.3 \
		HTTP::Proxy::BodyFilter.3 \
		HTTP::Proxy::BodyFilter::complete.3 \
		HTTP::Proxy::BodyFilter::htmlparser.3 \
		HTTP::Proxy::BodyFilter::htmltext.3 \
		HTTP::Proxy::BodyFilter::lines.3 \
		HTTP::Proxy::BodyFilter::save.3 \
		HTTP::Proxy::BodyFilter::simple.3 \
		HTTP::Proxy::BodyFilter::tags.3 \
		HTTP::Proxy::Engine.3 \
		HTTP::Proxy::Engine::Legacy.3 \
		HTTP::Proxy::Engine::NoFork.3 \
		HTTP::Proxy::Engine::ScoreBoard.3 \
		HTTP::Proxy::Engine::Threaded.3 \
		HTTP::Proxy::FilterStack.3 \
		HTTP::Proxy::HeaderFilter.3 \
		HTTP::Proxy::HeaderFilter::simple.3 \
		HTTP::Proxy::HeaderFilter::standard.3

.include <bsd.port.mk>
