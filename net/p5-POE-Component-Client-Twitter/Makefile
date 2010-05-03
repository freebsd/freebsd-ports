# New ports collection makefile for:	p5-POE-Component-Client-Twitter
# Date created:		2008-04-13
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Twitter
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	POE chat component for twitter.com

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Client-HTTP>=0:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

BROKEN=		incomplete dependencies

MAN3=		POE::Component::Client::Twitter.3

.include <bsd.port.mk>
