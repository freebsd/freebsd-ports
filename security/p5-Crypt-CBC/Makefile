# New ports collection makefile for:	p5-Crypt-CBC
# Date created:				October 20th 1996
# Whom:	      				Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-CBC
PORTVERSION=	2.08
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl5 interface to Cipher Block Chaining with DES and IDEA

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MAN3=		Crypt::CBC.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
