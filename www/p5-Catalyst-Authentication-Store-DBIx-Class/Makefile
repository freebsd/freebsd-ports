# New ports collection makefile for:	p5-Catalyst-Authentication-Store-DBIx-Class
# Date created:				2008-09-18
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Authentication-Store-DBIx-Class
PORTVERSION=	0.1501
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	A storage class for Catalyst Authentication using DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Model-DBIC-Schema>=0.18:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Plugin-Authentication>=0.10008:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Runtime>=5.8:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-DBIx-Class>=0.08:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Authentication::Realm::SimpleDB.3 \
		Catalyst::Authentication::Store::DBIx::Class.3 \
		Catalyst::Authentication::Store::DBIx::Class::User.3 \

.include <bsd.port.mk>
