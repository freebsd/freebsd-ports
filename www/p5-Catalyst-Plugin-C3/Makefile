# Ports collection makefile for: p5-Catalyst-Plugin-C3
# Date created:			 Apr 6, 2007
# Whom:				 lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-C3
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst Plugin to subvert NEXT to use Class::C3

BUILD_DEPENDS=	p5-Algorithm-C3>=0.06:${PORTSDIR}/devel/p5-Algorithm-C3 \
		p5-Catalyst-Runtime>=5.7006:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-C3>=0.14:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::C3.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
