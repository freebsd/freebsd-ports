# New ports collection makefile for:	mail/p5-MIME-Lite-TT-HTML
# Date created:				22 March 2008
# Whom:					Tuc <freebsd-ports@t-b-o-h.net>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite-TT-HTML
PORTVERSION=	0.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	Create html mail with MIME::Lite and TT

BUILD_DEPENDS=	${SITE_PERL}/mach/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/HTML/FormatText/WithLinks.pm:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks
RUN_DEPENDS=	${SITE_PERL}/mach/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/HTML/FormatText/WithLinks.pm:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks

PERL_CONFIGURE=	yes
PERL_MODBUILD=	yes

MAN3=	MIME::Lite::TT::HTML.3

.include <bsd.port.mk>
