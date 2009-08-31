# New ports collection makefile for:	p5-Catalyst-Plugin-RunAfterRequest
# Date created:		2009-08-30
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-RunAfterRequest
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Run code after the response has been sent

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.8004:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Catalyst-Component-InstancePerContext>=0:${PORTSDIR}/www/p5-Catalyst-Component-InstancePerContext	\
		p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::RunAfterRequest.3 \
			Catalyst::Model::Role::RunAfterRequest.3

.include <bsd.port.mk>
