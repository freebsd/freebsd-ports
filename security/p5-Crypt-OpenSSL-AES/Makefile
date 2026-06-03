PORTNAME=	Crypt-OpenSSL-AES
DISTVERSION=	0.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMLEGGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl wrapper around OpenSSL's AES library
WWW=		https://metacpan.org/release/Crypt-OpenSSL-AES

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0.10:security/p5-Crypt-OpenSSL-Guess \
		p5-File-Which>=0:sysutils/p5-File-Which
TEST_DEPENDS=	p5-Crypt-URandom>=0:security/p5-Crypt-URandom

USES=		perl5 shebangfix ssl
USE_PERL5=	configure
SHEBANG_FILES=	t/*
perl_OLD_CMD=	.*perl
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

pre-configure:
	${REINPLACE_CMD} -e 's|%%SSLBIN%%|${OPENSSLBASE}/bin/openssl|g' \
		${WRKSRC}/t/00-openssl-version.t \
		${WRKSRC}/t/09-key-size.t

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}/auto/Crypt/OpenSSL/AES/AES.so

.include <bsd.port.mk>
