# New ports collection makefile for:	www/p5-Catalyst-Example-InstantCRUD
# Date created:				11 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Example-InstantCRUD
PORTVERSION=	0.034
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create a working CRUD Catalyst example with the least of effort

BUILD_DEPENDS=	\
	p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
	p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
	p5-Catalyst-Plugin-Authentication>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
	p5-Catalyst-Plugin-Authentication-Store-DBIC>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication-Store-DBIC \
	p5-Catalyst-Plugin-ConfigLoader>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
	p5-Catalyst-Plugin-HTML-Widget>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-HTML-Widget \
	p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
	p5-Catalyst-Plugin-Session-Store-FastMmap>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-FastMmap \
	p5-Catalyst-Plugin-StackTrace>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-StackTrace \
	p5-Catalyst-Plugin-Static-Simple>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-View-TT>=0.21:${PORTSDIR}/www/p5-Catalyst-View-TT \
	p5-DBIx-Class>=0.08003:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-DigestColumns>=0:${PORTSDIR}/databases/p5-DBIx-Class-DigestColumns \
	p5-DBIx-Class-Schema-Loader>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-HTML-Widget>=1.10:${PORTSDIR}/www/p5-HTML-Widget \
	p5-HTML-Widget-DBIC>=0:${PORTSDIR}/www/p5-HTML-Widget-DBIC \
	p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser \
	p5-Template-Plugin-Class>=0:${PORTSDIR}/www/p5-Template-Plugin-Class \
	p5-URI>=0:${PORTSDIR}/net/p5-URI \
	p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN1=	instantcrud.pl.1
MAN3=	Catalyst::Example::Controller::InstantCRUD.3 \
	Catalyst::Example::Controller::InstantCRUD::REST.3 \
	Catalyst::Example::InstantCRUD.3 \
	Catalyst::Helper::Controller::InstantCRUD.3 \
	Catalyst::Helper::InstantCRUD.3 \
	Catalyst::Helper::Model::InstantCRUD.3 \
	Catalyst::Helper::View::InstantCRUD.3 \
	Catalyst::Plugin::Auth::Utils.3

.include <bsd.port.mk>
