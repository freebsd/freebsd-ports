PORTNAME=	Crypt-X509-CRL
PORTVERSION=	0.4
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Object oriented X.509 certificate revocation list parser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-ASN1>=0.19:converters/p5-Convert-ASN1

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	${SITE_MAN3_REL}/Crypt::X509::CRL.3.gz \
		${SITE_PERL_REL}/Crypt/X509/CRL.pm

.include <bsd.port.mk>
