PORTNAME=	Crypt-PasswdMD5
DISTVERSION=	1.46
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSAVAGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides interoperable MD5-based crypt() function
WWW=		https://metacpan.org/release/Crypt-PasswdMD5

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE-GPL-3

TEST_DEPENDS=	p5-Crypt-URandom>=0:security/p5-Crypt-URandom

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
