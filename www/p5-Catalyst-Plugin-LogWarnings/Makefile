# Ports collection makefile for: p5-Catalyst-Plugin-LogWarnings
# Date created:			 Apr 6, 2007
# Whom:				 lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-LogWarnings
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Log perl warnings to your Catalyst log object

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Catalyst-Plugin-C3>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-C3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::LogWarnings.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
