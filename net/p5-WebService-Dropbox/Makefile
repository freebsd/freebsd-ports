# Created by: Lung-Pin Chang <changlp@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	WebService-Dropbox
PORTVERSION=	2.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Perl interface to Dropbox API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE


MY_DEPENDS=	p5-HTTP-Message>=6.06:www/p5-HTTP-Message \
		p5-JSON>=2.59:converters/p5-JSON \
		p5-LWP-Protocol-https>=6.04:www/p5-LWP-Protocol-https \
		p5-Net-OAuth>=0.28:net/p5-Net-OAuth \
		p5-URI>=1.60:net/p5-URI \
		p5-libwww>=6.05:www/p5-libwww
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

OPTIONS_DEFINE=	FURL
OPTIONS_DEFAULT=FURL
FURL_DESC=	Support the (faster) Furl HTTP client library

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

FURL_BUILD_DEPENDS=	p5-Furl>=2.19:www/p5-Furl \
			p5-IO-Socket-SSL>=1.954:security/p5-IO-Socket-SSL \
			p5-JSON-XS>=3.02:converters/p5-JSON-XS
FURL_RUN_DEPENDS=	${FURL_BUILD_DEPENDS}

.include <bsd.port.mk>
