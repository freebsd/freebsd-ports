# New ports collection makefile for:	p5-Crypt-Simple
# Date created:	   01 Jun 2010
# Whom:		   Alexander Kriventsov <avk@vl.ru>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Simple
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	avk@vl.ru
COMMENT=	Perl encrypt stuff simply

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Crypt::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
