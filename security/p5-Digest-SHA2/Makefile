# New ports collection makefile for:	Digest-SHA2
# Date created:	   06 August 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA2
PORTVERSION=	1.1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to the SHA-2 algorithms

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
