# New ports collection makefile for:	www/p5-Bundle-Catalyst
# Date created:				12 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bundle-Catalyst
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Bundle to install most of the Catalyst modules

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst \
		${SITE_PERL}/Catalyst/Plugin/FormValidator.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator \
		${SITE_PERL}/Catalyst/Plugin/Prototype.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Prototype \
		${SITE_PERL}/Catalyst/Plugin/Session/FastMmap.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-FastMmap \
		${SITE_PERL}/Catalyst/Plugin/Static.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Static \
		${SITE_PERL}/Catalyst/Model/CDBI.pm:${PORTSDIR}/www/p5-Catalyst-Model-CDBI \
		${SITE_PERL}/Catalyst/View/TT.pm:${PORTSDIR}/www/p5-Catalyst-View-TT
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Bundle::Catalyst.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
