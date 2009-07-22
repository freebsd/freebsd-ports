# New ports collection makefile for:	p5-Digest-HMAC
# Date created:				2001/12/11
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	Digest-HMAC
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to HMAC Message-Digest Algorithms

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::HMAC.3 \
		Digest::HMAC_MD5.3 \
		Digest::HMAC_SHA1.3

.include <bsd.port.mk>
