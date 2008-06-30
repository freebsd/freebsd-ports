# New ports collection makefile for:	p5-Catalyst-Model-LDAP
# Date created:		2008-06-30
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-LDAP
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/D/DA/DANIELTWC
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	LDAP model class for Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Model::LDAP::Entry.3 Catalyst::Model::LDAP::Search.3 \
	Catalyst::Helper::Model::LDAP.3 Catalyst::Model::LDAP::Connection.3 \
	Catalyst::Model::LDAP.3

.include <bsd.port.mk>
