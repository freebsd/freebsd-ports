# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Async-HTTP
PORTVERSION=	0.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use HTTP with IO::Async

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Future>=0.28:devel/p5-Future \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Async>=0.59:devel/p5-IO-Async \
		p5-Struct-Dumb>=0.07:devel/p5-Struct-Dumb \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL \
		p5-Test-Identity>=0:devel/p5-Test-Identity \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

OPTIONS_DEFINE=	SSL

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

SSL_BUILD_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL
SSL_RUN_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.29:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.29:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
