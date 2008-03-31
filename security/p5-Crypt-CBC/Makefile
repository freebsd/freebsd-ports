# New ports collection makefile for:	p5-Crypt-CBC
# Date created:				October 20th 1996
# Whom:	      				Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-CBC
PORTVERSION=	2.27
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to Cipher Block Chaining with DES and IDEA

PERL_CONFIGURE=	yes

MAN3=		Crypt::CBC.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS=	${RUN_DEPENDS}
.endif

.include <bsd.port.post.mk>
