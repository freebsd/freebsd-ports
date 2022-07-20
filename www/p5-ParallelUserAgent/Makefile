PORTNAME=	ParallelUserAgent
PORTVERSION=	2.62
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSOUTH
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extension for LWP to allow parallel HTTP and FTP access

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=5.64:www/p5-libwww

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

.include <bsd.port.mk>
