# New ports collection makefile for:	p5-Crypt-SSLeay
# Date created:				December-15-2000
# Whom:	      				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.23
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	"/usr"
USE_OPENSSL=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::SSLeay.3

.include <bsd.port.mk>
