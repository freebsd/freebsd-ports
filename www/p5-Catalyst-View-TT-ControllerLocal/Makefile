# New ports collection makefile for:	www/p5-Catalyst-View-TT-ControllerLocal
# Date created:				11 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-TT-ControllerLocal
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst TT View with template names relative to the Controller

BUILD_DEPENDS=	p5-Catalyst>=0:${PORTSDIR}/www/p5-Catalyst \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::TTControllerLocal.3 \
	Catalyst::View::TT::ControllerLocal.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500801
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
