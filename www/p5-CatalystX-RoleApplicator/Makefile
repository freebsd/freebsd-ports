# New ports collection makefile for:	p5-CatalystX-RoleApplicator
# Date created:		January 31, 2010
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	CatalystX-RoleApplicator
PORTVERSION=	0.005
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Apply roles to your Catalyst application-related classes

RUN_DEPENDS=	p5-MooseX-RelatedClassRoles>=0.003:${PORTSDIR}/devel/p5-MooseX-RelatedClassRoles \
	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \

PERL_CONFIGURE=	yes

MAN3=	CatalystX::RoleApplicator.3

.include <bsd.port.mk>
