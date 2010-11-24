# New ports collection makefile for:	p5-Net-Riak
# Date created:		2010-11-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Riak
PORTVERSION=	0.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interface to Riak

RUN_DEPENDS=	p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Net::Riak.3 \
		Net::Riak::Bucket.3 \
		Net::Riak::Client.3 \
		Net::Riak::Link.3 \
		Net::Riak::LinkPhase.3 \
		Net::Riak::MapReduce.3 \
		Net::Riak::MapReducePhase.3 \
		Net::Riak::Object.3 \
		Net::Riak::Role::Base.3 \
		Net::Riak::Role::Hosts.3 \
		Net::Riak::Role::MapReduce.3 \
		Net::Riak::Role::REST.3 \
		Net::Riak::Role::Replica.3 \
		Net::Riak::Role::UserAgent.3

.include <bsd.port.mk>
