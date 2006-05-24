# New ports collection makefile for:	p5-Mail-IMAPTalk
# Date created:				24 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-IMAPTalk
PORTVERSION=	1.03
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	IMAP client interface with lots of features

MAN3=	Mail::IMAPTalk.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.0.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
