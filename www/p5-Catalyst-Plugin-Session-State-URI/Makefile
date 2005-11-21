# Ports collection makefile for:	p5-Catalyst-Plugin-Session-State-URI
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-State-URI
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-URI-Find>=0.13:${PORTSDIR}/textproc/p5-URI-Find
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Session::State::URI.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
