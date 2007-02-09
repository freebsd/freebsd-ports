# New ports collection makefile for:	p5-Crypt-OICQ
# Date created:				Aug 01, 2006
# Whom:	      				Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-OICQ
PORTVERSION=	1.1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Cryptographic algorithm used by OICQ protocol

PERL_CONFIGURE=	yes

MAN3=		Crypt::OICQ.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires at least Perl 5.8. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
