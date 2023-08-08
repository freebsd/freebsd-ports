PORTNAME=	Crypt-X509
PORTVERSION=	0.55
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl extension to parse X.509 certificates
WWW=		https://metacpan.org/release/Crypt-X509

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/lib/Crypt/X509.pm

RUN_DEPENDS=	p5-Convert-ASN1>=0:converters/p5-Convert-ASN1

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
USE_PERL5=	configure
NO_ARCH=	yes
PORTSCOUT=	limit:v?([0-9]+\.)+[0-9]+ \
		site:https://github.com/openxpki/Crypt-X509/tags

.include <bsd.port.mk>
