# New ports collection makefile for:	p5-Net-AMQP
# Date created:		2011-10-29
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-AMQP
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Advanced Message Queue Protocol (de)serialization and representation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
    		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
    		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
    		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		Net::AMQP.3 \
		Net::AMQP::Common.3 \
		Net::AMQP::Frame.3 \
		Net::AMQP::Frame::Body.3 \
		Net::AMQP::Frame::Header.3 \
		Net::AMQP::Frame::Heartbeat.3 \
		Net::AMQP::Frame::Method.3 \
		Net::AMQP::Frame::OOBBody.3 \
		Net::AMQP::Frame::OOBHeader.3 \
		Net::AMQP::Frame::OOBMethod.3 \
		Net::AMQP::Frame::Trace.3 \
		Net::AMQP::Protocol.3 \
		Net::AMQP::Protocol::Base.3

.include <bsd.port.mk>
