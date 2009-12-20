# New ports collection makefile for:	p5-Mail-Tools
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Tools
PORTVERSION=	2.05
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MailTools-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl5 modules for dealing with Internet e-mail messages

RUN_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

PERL_CONFIGURE=	5.8.1+

MAN3=		Mail::Address.3 \
		Mail::Cap.3 \
		Mail::Field.3 \
		Mail::Field::AddrList.3 \
		Mail::Field::Date.3 \
		Mail::Field::Generic.3 \
		Mail::Filter.3 \
		Mail::Header.3 \
		Mail::Internet.3 \
		Mail::Mailer.3 \
		Mail::Send.3 \
		Mail::Util.3

.include <bsd.port.mk>
