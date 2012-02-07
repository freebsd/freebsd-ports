# New ports collection makefile for:	p5-Catalyst-ActionRole-ACL
# Date created:		2011-05-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-ActionRole-ACL
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CONVERTER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	User role-based authorization action class

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Controller-ActionRole>=0:${PORTSDIR}/www/p5-Catalyst-Controller-ActionRole \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Controller-ActionRole>=0:${PORTSDIR}/www/p5-Catalyst-Controller-ActionRole \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=	Catalyst::Action::Role::ACL.3 Catalyst::ActionRole::ACL.3

.include <bsd.port.mk>
