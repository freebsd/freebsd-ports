# Ports collection makefile for:	p5-Catalyst-Controller-FormBuilder
# Date created:				Mar 30 2007
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-FormBuilder
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst FormBuilder Base Controller

BUILD_DEPENDS=	p5-CGI-FormBuilder>=3.02:${PORTSDIR}/www/p5-CGI-FormBuilder \
		p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Accessor>=0.25:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Tie-IxHash>=1.21:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=1.13:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Catalyst-View-TT>=0.23:${PORTSDIR}/www/p5-Catalyst-View-TT
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Controller::FormBuilder.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^(recommends|requires),' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
