# Ports collection makefile for:	p5-Catalyst-Plugin-Session
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Generic Catalyst Session plugin

BUILD_DEPENDS=	p5-Catalyst>=5.50:${PORTSDIR}/www/p5-Catalyst \
		p5-Test-MockObject>=1.01:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Digest>=0:${PORTSDIR}/security/p5-Digest \
		p5-Object-Signature>=0:${PORTSDIR}/devel/p5-Object-Signature \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Session.3 \
	Catalyst::Plugin::Session::State.3 \
	Catalyst::Plugin::Session::Store.3 \
	Catalyst::Plugin::Session::Store::Dummy.3 \
	Catalyst::Plugin::Session::Test::Store.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
