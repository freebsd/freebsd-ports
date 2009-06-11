# New ports collection makefile for:	Digest
# Date created:	   28 May 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Digest
PORTVERSION=	1.16
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules that calculate message digests

PERL_CONFIGURE=	yes

MAN3=		Digest.3 Digest::base.3 Digest::file.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
