# New ports collection makefile for:	p5-Crypt-DES
# Date created:				October 20th 1996
# Whom:	      				Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Crypt-CBC
PORTVERSION=	1.20
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
DISTNAME=	Crypt-CBC-1.20

MAINTAINER=	markm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/5.005/i386-freebsd/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

RESTRICTED=	"Crypto; export-controlled"

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::CBC.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
