# Created by: Mosconi <mosconi.rmg@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-CA
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL CA API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

# Note: The Devel::Mallinfo dependency doesn't work on FreeBSD; mallinfo()
# is a GNU libc function.
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-ASN1>=0.02:converters/p5-Convert-ASN1 \
		p5-Devel-Leak>=0:devel/p5-Devel-Leak \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Inline>=0.40:devel/p5-Inline \
		p5-Inline-C>=0:devel/p5-Inline-C \
		p5-Net-SSLeay>=1.25:security/p5-Net-SSLeay
TEST_DEPENDS=	p5-Test-Group>=0:devel/p5-Test-Group \
		p5-Test-Taint>=0:devel/p5-Test-Taint

BROKEN_SSL=	openssl

USES=		perl5 ssl
USE_PERL5=	modbuild
CONFIGURE_ARGS=	--openssl-cflags=-L${OPENSSLINC} --openssl-ldflags="-I${OPENSSLLIB} ${OPENSSL_LDFLAGS}"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=        Does not support OpenSSL 1.1
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/CA/*/*.so

.include <bsd.port.mk>
