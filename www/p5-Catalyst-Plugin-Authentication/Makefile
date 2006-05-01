# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

BUILD_DEPENDS=	p5-Catalyst>=5.49:${PORTSDIR}/www/p5-Catalyst \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Authentication.3 \
	Catalyst::Plugin::Authentication::Credential::Password.3 \
	Catalyst::Plugin::Authentication::Store.3 \
	Catalyst::Plugin::Authentication::Store::Minimal.3 \
	Catalyst::Plugin::Authentication::Store::Minimal::Backend.3 \
	Catalyst::Plugin::Authentication::User.3 \
	Catalyst::Plugin::Authentication::User::Hash.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
