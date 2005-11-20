# Ports collection makefile for:	p5-Catalyst-Plugin-Session
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Generic Catalyst Session plugin

BUILD_DEPENDS=	p5-Catalyst>=5.50:${PORTSDIR}/www/p5-Catalyst \
		p5-Digest>=0:${PORTSDIR}/security/p5-Digest \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp
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
