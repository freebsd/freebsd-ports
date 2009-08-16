# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication-Store-DBIC
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication-Store-DBIC
PORTVERSION=	0.11000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0*$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Authentication/authorization on a DBIx::Class/Class::DBI model

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Plugin-Authentication>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Set-Object>=1.14:${PORTSDIR}/devel/p5-Set-Object \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Catalyst-Plugin-Authorization-Roles>=0.03:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-Roles \
		p5-Catalyst-Plugin-Session-State-Cookie>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie
BUILD_DEPENDS=	${RUN_DEPENDS}

DEPRECATED=	Use p5-Catalyst-Authentication-Store-DBIx-Class instead.

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Authentication::Store::DBIC.3 \
	Catalyst::Plugin::Authentication::Store::DBIC::Backend.3 \
	Catalyst::Plugin::Authentication::Store::DBIC::User.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^\s*feature/ .. /;\s*$$/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
