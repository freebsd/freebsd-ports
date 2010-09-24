# New ports collection makefile for:	mail/p5-MIME-Lite-TT
# Date created:				23 March 2008
# Whom:					Tuc <freebsd-ports@t-b-o-h.net>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite-TT
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	TT enabled MIME::Lite wrapper

BUILD_DEPENDS=	${SITE_PERL}/mach/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/mach/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	MIME::Lite::TT.3

.include <bsd.port.mk>
