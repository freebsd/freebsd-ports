# New ports collection makefile for:	Crypt-Twofish
# Date created:				Wed Jan  3 16:29:03 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-Twofish
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl module implementing the Twofish cipher

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::Twofish.3

.include <bsd.port.mk>
