# New ports collection makefile for:	p5-Net-Riak
# Date created:		2010-11-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Riak
PORTVERSION=	0.15.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Riak

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Google-ProtocolBuffers>=0:${PORTSDIR}/devel/p5-Google-ProtocolBuffers \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Traits>=0:${PORTSDIR}/devel/p5-MooseX-Traits \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Net::Riak.3 \
		Net::Riak::Bucket.3 \
		Net::Riak::Client.3 \
		Net::Riak::Link.3 \
		Net::Riak::LinkPhase.3 \
		Net::Riak::MapReduce.3 \
		Net::Riak::MapReducePhase.3 \
		Net::Riak::Object.3 \
		Net::Riak::Types.3 \
		Net::Riak::Role::Base.3 \
		Net::Riak::Role::Hosts.3 \
		Net::Riak::Role::MapReduce.3 \
		Net::Riak::Role::REST.3 \
		Net::Riak::Role::Replica.3 \
		Net::Riak::Role::UserAgent.3 \
		Net::Riak::Role::REST::Bucket.3 \
		Net::Riak::Role::PBC::Message.3 \
		Net::Riak::Transport::PBC.3 \
		Net::Riak::Role::PBC.3 \
		Net::Riak::Role::REST::Object.3 \
		Net::Riak::Role::PBC::Link.3 \
		Net::Riak::Role::REST::MapReduce.3 \
		Net::Riak::Transport::PBC::Transport.3 \
		Net::Riak::Role::PBC::Object.3 \
		Net::Riak::Transport::REST.3 \
		Net::Riak::Role::PBC::Bucket.3 \
		Net::Riak::Transport::PBC::Code.3 \
		Net::Riak::Transport::PBC::Message.3 \
		Net::Riak::Role::REST::Link.3 \
		Net::Riak::Role::PBC::MapReduce.3

.include <bsd.port.mk>
