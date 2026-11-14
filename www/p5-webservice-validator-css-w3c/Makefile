PORTNAME=	WebService-Validator-CSS-W3C
DISTVERSION=	0.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Experimental interface to the W3C CSS Validation online service
WWW=		https://metacpan.org/release/WebService-Validator-CSS-W3C/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
MY_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/eg/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
