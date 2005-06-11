# New ports collection makefile for:    p5-Digest-MD5
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	Digest-MD5
PORTVERSION=	2.33
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl5 interface to the MD5 algorithm

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Digest::MD5.3

.include <bsd.port.mk>
