# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-AnyUA
PORTVERSION=	0.904
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP user agent programming interface unification layer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0:devel/p5-Future \
		p5-Module-Loader>=0:devel/p5-Module-Loader
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-namespace-clean>=0:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
