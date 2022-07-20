PORTNAME=	OpenCA-OpenSSL
PORTVERSION=	2.0.29
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MADWOLF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl crypto extension to OpenSSL

BROKEN_SSL=	base openssl
BROKEN_SSL_REASON_openssl=	incomplete definition of type 'struct x509_st'

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-X500-DN>=0:net/p5-X500-DN

USES=		perl5 ssl
USE_PERL5=	configure
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${SSL_DEFAULT} == base || ${SSL_DEFAULT} == openssl)
BROKEN=		Does not support OpenSSL 1.1
.endif

.include <bsd.port.mk>
