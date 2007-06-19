# Ports collection makefile for:	p5-Catalyst-Plugin-FormCanary
# Date created:				Jun 19, 2007
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FormCanary
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Check that forms are submitted from your site

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormCanary.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
