# New ports collection makefile for:	Crypt-Twofish
# Date created:				Wed Jan  3 16:29:03 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-Twofish
PORTVERSION=	2.12
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl module implementing the Twofish cipher

PERL_CONFIGURE=	yes

MAN3=		Crypt::Twofish.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
