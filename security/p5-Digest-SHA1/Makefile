# New ports collection makefile for:	p5-Digest-SHA1
# Date created:				30 March 2001
# Whom:					Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA1
PORTVERSION=	2.13
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the SHA-1 Algorithm

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA1.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
BUILD_DEPENDS+=	p5-Digest>=1.00:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS+=	p5-Digest>=1.00:${PORTSDIR}/security/p5-Digest
.endif

.include <bsd.port.post.mk>
