# New ports collection makefile for:	p5-Net-Rendezvous-Publish
# Date created:		2009-07-12
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Net-Rendezvous-Publish
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Publish Rendezvous services

BUILD_DEPENDS=	p5-Class-Accessor-Lvalue>=0:${PORTSDIR}/devel/p5-Class-Accessor-Lvalue \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Rendezvous::Publish::Service.3 \
		Net::Rendezvous::Publish.3

.include <bsd.port.mk>
