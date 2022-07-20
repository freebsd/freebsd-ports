PORTNAME=	Filter-Crypto
PORTVERSION=	2.09
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PAR-Packer>=0:devel/p5-PAR-Packer
TEST_DEPENDS=	p5-CPAN-Changes>=0:devel/p5-CPAN-Changes

USES=		perl5 ssl
USE_PERL5=	configure

CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

.include <bsd.port.mk>
