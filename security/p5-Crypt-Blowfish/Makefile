PORTNAME=	Crypt-Blowfish
PORTVERSION=	2.14
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Blowfish encryption algorithm
WWW=		https://metacpan.org/release/Crypt-Blowfish

LICENSE=	BSD4CLAUSE  # w/o 3'th clause
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	p5-Crypt-CBC>=0:security/p5-Crypt-CBC

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Blowfish/Blowfish.so

.include <bsd.port.mk>
