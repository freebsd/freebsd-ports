# New ports collection makefile for:	p5-Jifty-Plugin-Authentication-Ldap
# Date created:		14 June, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Jifty-Plugin-Authentication-Ldap
PORTVERSION=	1.00
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	LDAP Authentication Plugin for Jifty Apps

BUILD_DEPENDS=	p5-Jifty>=0:${PORTSDIR}/www/p5-Jifty \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Jifty::Plugin::Authentication::Ldap.3 \
		Jifty::Plugin::Authentication::Ldap::Action::LDAPLogin.3 \
		Jifty::Plugin::Authentication::Ldap::Action::LDAPLogout.3 \
		Jifty::Plugin::Authentication::Ldap::View.3 \
		Jifty::Plugin::Authentication::Ldap::Mixin::Model::User.3

.include <bsd.port.mk>
