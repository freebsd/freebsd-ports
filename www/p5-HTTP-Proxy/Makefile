# New ports collection makefile for:	p5-HTTP-Proxy
# Date created:				16 April 2003
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	HTTP-Proxy
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A pure Perl HTTP proxy

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

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
		HTTP::Proxy::HeaderFilter.3 \
		HTTP::Proxy::HeaderFilter::simple.3 \
		HTTP::Proxy::HeaderFilter::standard.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
