# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication
PORTVERSION=	0.10017
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BO/BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

RUN_DEPENDS=	p5-Catalyst-Plugin-Session>=0.10:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PORTSCOUT=	skipv:0.100092

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Authentication::Credential::Password.3 \
	Catalyst::Authentication::Credential::Remote.3 \
	Catalyst::Authentication::Realm.3 \
	Catalyst::Authentication::Realm::Compatibility.3 \
	Catalyst::Authentication::Realm::Progressive.3 \
	Catalyst::Authentication::Store.3 \
	Catalyst::Authentication::Store::Minimal.3 \
	Catalyst::Authentication::Store::Null.3 \
	Catalyst::Authentication::User.3 \
	Catalyst::Authentication::User::Hash.3 \
	Catalyst::Plugin::Authentication.3 \
	Catalyst::Plugin::Authentication::Credential::Password.3 \
	Catalyst::Plugin::Authentication::Internals.3 \
	Catalyst::Plugin::Authentication::Store::Minimal.3 \
	Catalyst::Plugin::Authentication::User.3 \
	Catalyst::Plugin::Authentication::User::Hash.3

post-extract:
	@${REINPLACE_CMD} -e '/^test_requires/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
