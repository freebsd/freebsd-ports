# New ports collection makefile for:	p5-Mail-QuoteWrap
# Date created:		Fri Sep 21 21:56:03 PDT 2001
# Whom:			Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-QuoteWrap
PORTVERSION=	0.01
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	MailQuoteWrap${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Provides wrapping functionality for quoted Email and Usenet messages

BUILD_DEPENDS=	${SITE_PERL}/Text/Format.pm:${PORTSDIR}/textproc/p5-Text-Format

PERL_CONFIGURE=	yes

MAN3=		Mail::QuoteWrap.3

.include <bsd.port.mk>
