PORTNAME=	WebService-Dropbox
PORTVERSION=	2.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to Dropbox API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=6.11:www/p5-HTTP-Message \
		p5-JSON>=2.94:converters/p5-JSON \
		p5-LWP-Protocol-https>=6.07:www/p5-LWP-Protocol-https \
		p5-Net-OAuth>=0:net/p5-Net-OAuth \
		p5-URI>=1.71:net/p5-URI \
		p5-libwww>=6.26:www/p5-libwww

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-IO-Socket-SSL>=2.048:security/p5-IO-Socket-SSL \
				p5-JSON-XS>=3.03:converters/p5-JSON-XS \
				p5-Software-License>=0:misc/p5-Software-License
#				p5-Furl>=3.11:www/p5-Furl

.include <bsd.port.mk>
