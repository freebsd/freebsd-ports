# Ports collection makefile for:	p5-Catalyst-Plugin-Session-State-URI
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-State-URI
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-TokeParser-Simple>=0:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Session::State::URI.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
