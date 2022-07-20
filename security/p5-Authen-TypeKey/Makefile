PORTNAME=	Authen-TypeKey
PORTVERSION=	0.05
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TypeKey authentication verification

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-libwww>=0:www/p5-libwww \
		p5-Module-Install>0:devel/p5-Module-Install

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	# Really old M::I code
	${RM} -r ${WRKSRC}/inc

.include <bsd.port.mk>
