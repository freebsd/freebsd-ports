# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	URI-cpan
PORTVERSION=	1.008
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	URLs that refer to things on the CPAN

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-DistnameInfo>=0:devel/p5-CPAN-DistnameInfo \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
