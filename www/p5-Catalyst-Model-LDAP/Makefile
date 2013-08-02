# Created by: Andrej Zverev <az@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-LDAP
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	LDAP model class for Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Model::LDAP::Entry.3 Catalyst::Model::LDAP::Search.3 \
	Catalyst::Helper::Model::LDAP.3 Catalyst::Model::LDAP::Connection.3 \
	Catalyst::Model::LDAP.3

.include <bsd.port.mk>
