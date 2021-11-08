# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>

PORTNAME=	Mcrypt
DISTVERSION=	2.5.7.0
PORTREVISION=	4
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JESUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Perl extension for the Mcrypt cryptography library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt

USES=		localbase:ldflags perl5
USE_PERL5=	configure
CONFIGURE_ENV=	MCRYPT_CPPFLAGS=${CPPFLAGS:Q} \
		MCRYPT_LDFLAGS=${LDFLAGS:Q}

post-patch:
	${REINPLACE_CMD} -e 's, -lltdl,,'\
		${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Mcrypt/Mcrypt.so

.include <bsd.port.mk>
