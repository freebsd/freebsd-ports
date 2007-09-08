# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication-Store-DBIC
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication-Store-DBIC
PORTVERSION=	0.07000
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0*$//}

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Authentication/authorization on a DBIx::Class/Class::DBI model

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Authentication>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Authorization-Roles>=0.03:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-Roles \
		p5-Set-Object>=1.14:${PORTSDIR}/devel/p5-Set-Object \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	Catalyst::Plugin::Authentication::Store::DBIC.3 \
	Catalyst::Plugin::Authentication::Store::DBIC::Backend.3 \
	Catalyst::Plugin::Authentication::Store::DBIC::User.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^\s*recommends/ .. /},$$/' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
