# New ports collection makefile for:	p5-Crypt-Random
# Date created:				Tue Sep 11 10:47:19 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Random
PORTVERSION=	1.11
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org

PERLBASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

BUILD_DEPENDS=	${PERLBASE}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${PERLBASE}/Class/Loader.pm:${PORTSDIR}/devel/p5-Class-Loader

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::Random.3

.include <bsd.port.mk>
