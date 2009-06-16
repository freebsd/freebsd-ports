# Ports collection Makefile for:		p5-AxKit-XSP-Sendmail
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-Sendmail
PORTVERSION=	1.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Simple SMTP mailer tag library for AxKit eXtesible Server Pages.

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid

MAN3=		AxKit::XSP::Sendmail.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
