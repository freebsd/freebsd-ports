# Ports collection Makefile for:		p5-AxKit-XSP-Sendmail
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-Sendmail
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	adam@migus.org
COMMENT=	Simple SMTP mailer tag library for AxKit eXtesible Server Pages.

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		AxKit::XSP::Sendmail.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
