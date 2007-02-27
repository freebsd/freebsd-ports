# New ports collection makefile for:	CipherSaber
# Date created:				Wed Jan  3 16:03:49 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-CipherSaber
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module providing an OO interface to CipherSaber encryption

BUILD_DEPENDS=	${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		Crypt::CipherSaber.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
