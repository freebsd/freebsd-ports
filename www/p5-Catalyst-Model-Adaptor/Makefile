# New ports collection makefile for:	p5-Catalyst-Model-Adaptor
# Date created:		2008-09-01
# Whom:			Vladimir Timofeev <vovkasm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-Adaptor
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Use a plain class as a Catalyst model

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::Model::Adaptor.3 \
	Catalyst::Helper::Model::Factory.3 \
	Catalyst::Helper::Model::Factory::PerRequest.3 \
	Catalyst::Model::Adaptor.3 \
	Catalyst::Model::Adaptor::Base.3 \
	Catalyst::Model::Factory.3 \
	Catalyst::Model::Factory::PerRequest.3

.include <bsd.port.mk>
