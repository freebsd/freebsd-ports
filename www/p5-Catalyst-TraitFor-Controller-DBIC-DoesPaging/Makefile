# New ports collection makefile for:	p5-Catalyst-TraitFor-Controller-DBIC-DoesPaging
# Date created:		2010-07-28
# Whom:			Alex Bakhtin <Alex.Bakhtin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-TraitFor-Controller-DBIC-DoesPaging
PORTVERSION=	1.001000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	Helps you paginate, search, sort, and more easily using DBIx::Class

RUN_DEPENDS=	p5-Catalyst-Model-DBIC-Schema>=0.29:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Runtime>=5.80000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-DBIx-Class>=0.08108:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.11:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker

USE_PERL5=	5.8.1+
PERL_CONFIGURE=	yes

MAN3=		Catalyst::TraitFor::Controller::DBIC::DoesPaging.3

.include <bsd.port.mk>
