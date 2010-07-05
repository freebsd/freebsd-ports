# New ports collection makefile for:    p5-Digest-MD5
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	Digest-MD5
PORTVERSION=	2.40
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the MD5 algorithm

PERL_CONFIGURE=	yes

MAN3=		Digest::MD5.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
RUN_DEPENDS+=	${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest
.endif

.include <bsd.port.post.mk>
