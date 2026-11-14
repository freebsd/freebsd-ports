PORTNAME=	W3C-LogValidator
DISTVERSION=	1.5
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Comprehensive validation tool for webmasters and web developers
WWW=		https://www.w3.org/QA/Tools/LogValidator/

LICENSE=	W3C
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	W3C Software Notice and License (2002-12-31)
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
MY_DEPENDS=	checklink:www/p5-W3C-LinkChecker \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Mail-Sendmail>=0:mail/p5-Mail-Sendmail \
		p5-WebService-Validator-CSS-W3C>=0:www/p5-webservice-validator-css-w3c \
		p5-WebService-Validator-HTML-W3C>=0:www/p5-webservice-validator-html-w3c

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
