# New ports collection makefile for:	p5-Mail-POP3Client
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-POP3Client
PORTVERSION=	2.16
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 module to talk to a POP3 (RFC1939) server

PERL_CONFIGURE=	YES

MAN3=		Mail::POP3Client.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This module requires perl version 5.6.1 or above
.endif

.include <bsd.port.post.mk>
