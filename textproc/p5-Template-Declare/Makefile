# New ports collection makefile for:	textproc/p5-Template-Declare
# Date created:				23 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Declare
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perlish declarative templates

BUILD_DEPENDS=	${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/HTML/Lint.pm:${PORTSDIR}/www/p5-HTML-Lint
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Declare.3 \
	Template::Declare::Tags.3

.include <bsd.port.mk>
