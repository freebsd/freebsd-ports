# Ports collection makefile for:	p5-Catalyst-Plugin-Session
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic Catalyst Session plugin

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7010:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Object-Signature>=0:${PORTSDIR}/devel/p5-Object-Signature \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Tie-RefHash>=1.34:${PORTSDIR}/devel/p5-Tie-RefHash
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Session.3 \
	Catalyst::Plugin::Session::State.3 \
	Catalyst::Plugin::Session::Store.3 \
	Catalyst::Plugin::Session::Store::Dummy.3 \
	Catalyst::Plugin::Session::Test::Store.3 \
	Catalyst::Plugin::Session::Tutorial.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^(is_upgrading_needed|test_requires)/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
