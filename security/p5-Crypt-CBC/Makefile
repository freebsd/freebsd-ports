# New ports collection makefile for:	p5-Crypt-DES
# Date created:				October 20th 1996
# Whom:	      				Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-CBC
PORTVERSION=	1.25
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	markm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

RESTRICTED=	"Crypto; export-controlled"

USE_PERL5=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::CBC.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
