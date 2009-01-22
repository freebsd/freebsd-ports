# New ports collection makefile for:	HTTP::Router
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Router
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Yet Another Path Router for HTTP

RUN_DEPENDS=	\
	p5-Mouse>=0.14:${PORTSDIR}/devel/p5-Mouse \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean \
	p5-URI-Template-Restrict>0:${PORTSDIR}/net/p5-URI-Template-Restrict \
	p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Lingua-EN-Inflect-Number>0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
	p5-String-CamelCase>0:${PORTSDIR}/textproc/p5-String-CamelCase \
	p5-Text-SimpleTemplate>0:${PORTSDIR}/textproc/p5-Text-SimpleTemplate

PERL_CONFIGURE=	yes

MAN3=		HTTP::Router.3 \
		HTTP::Router::Debug.3 \
		HTTP::Router::Mapper.3 \
		HTTP::Router::Match.3 \
		HTTP::Router::Resources.3 \
		HTTP::Router::Route.3 \
		HTTP::Router::RouteSet.3

.include <bsd.port.mk>
