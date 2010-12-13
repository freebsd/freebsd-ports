# New ports collection makefile for:	www/p5-WWW-Mechanize-TreeBuilder
# Date created:				25 December 2009
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-TreeBuilder
PORTVERSION=	1.10003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	WWW::Mechanize::TreeBuilder

BUILD_DEPENDS=	${SITE_PERL}/MooseX/Role/Parameterized.pm:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Test/WWW/Mechanize.pm:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		${SITE_PERL}/${PERL_ARCH}/Moose.pm:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WWW::Mechanize::TreeBuilder.3

.include <bsd.port.mk>
