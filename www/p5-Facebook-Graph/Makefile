# New ports collection makefile for:	Facebook::Graph
# Date created:		08 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Facebook-Graph
PORTVERSION=	1.0301
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIZEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to integrate your apps with Facebook

RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
	p5-DateTime>=0.61:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-Strptime>=1.4000:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
	p5-JSON>=2.16:${PORTSDIR}/converters/p5-JSON \
	p5-libwww>=6.02:${PORTSDIR}/www/p5-libwww \
	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https \
	p5-MIME-Base64-URLSafe>=0.01:${PORTSDIR}/converters/p5-MIME-Base64-URLSafe \
	p5-Mozilla-CA>=20110409:${PORTSDIR}/www/p5-Mozilla-CA \
	p5-Ouch>=0.0400:${PORTSDIR}/devel/p5-Ouch \
	p5-URI>=1.54:${PORTSDIR}/net/p5-URI \
	p5-URI-Encode>=0.02:${PORTSDIR}/www/p5-URI-Encode
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Facebook::Graph.3 \
	Facebook::Graph::AccessToken.3 \
	Facebook::Graph::AccessToken::Response.3 \
	Facebook::Graph::Authorize.3 \
	Facebook::Graph::Cookbook.3 \
	Facebook::Graph::Cookbook::Recipe1.3 \
	Facebook::Graph::Cookbook::Recipe2.3 \
	Facebook::Graph::Picture.3 \
	Facebook::Graph::Publish.3 \
	Facebook::Graph::Publish::Checkin.3 \
	Facebook::Graph::Publish::Comment.3 \
	Facebook::Graph::Publish::Event.3 \
	Facebook::Graph::Publish::Like.3 \
	Facebook::Graph::Publish::Link.3 \
	Facebook::Graph::Publish::Note.3 \
	Facebook::Graph::Publish::Post.3 \
	Facebook::Graph::Publish::RSVPAttending.3 \
	Facebook::Graph::Publish::RSVPDeclined.3 \
	Facebook::Graph::Publish::RSVPMaybe.3 \
	Facebook::Graph::Query.3 \
	Facebook::Graph::Response.3 \
	Facebook::Graph::Role::Uri.3 \
	Facebook::Graph::Session.3

.include <bsd.port.mk>
