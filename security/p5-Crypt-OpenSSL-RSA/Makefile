# New ports collection makefile for:    p5-Crypt-OpenSSL-RSA
# Date created:				2001/08/27
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenSSL-RSA
PORTVERSION=	0.16
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Crypt/OpenSSL/Random.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-Random
RUN_DEPENDS=	${BUILD_DEPENDS}

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MAN3=		Crypt::OpenSSL::RSA.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
