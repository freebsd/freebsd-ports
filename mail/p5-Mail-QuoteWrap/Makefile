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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/Format.pm:${PORTSDIR}/textproc/p5-Text-Format

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::QuoteWrap.3

.include <bsd.port.mk>
