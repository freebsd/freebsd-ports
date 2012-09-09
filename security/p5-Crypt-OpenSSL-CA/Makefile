# New ports collection makefile for:	p5-Crypt-OpenSSL-CA
# Date created:		2011/08/25
# Whom:			Mosconi <mosconi.rmg@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenSSL-CA
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL CA API

# Note: The Devel::Mallinfo dependency doesn't work on FreeBSD; mallinfo()
# is a GNU libc function.
BUILD_DEPENDS=	p5-Convert-ASN1>=0.02:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-Devel-Leak>=0:${PORTSDIR}/devel/p5-Devel-Leak \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Inline>=0.4:${PORTSDIR}/devel/p5-Inline \
		p5-Net-SSLeay>=1.25:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Group>=0:${PORTSDIR}/devel/p5-Test-Group

PERL_CONFIGURE=	yes

MAN3=		Crypt::OpenSSL::CA.3 \
		Crypt::OpenSSL::CA::AlphabetSoup.3 \
		Crypt::OpenSSL::CA::Inline::C.3 \
		Crypt::OpenSSL::CA::Resources.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Module-Build>=0.2900:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
