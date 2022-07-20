PORTNAME=	Net-Address-Ethernet
PORTVERSION=	1.129
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find hardware ethernet address

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Ifconfig-Wrapper>=0:net/p5-Net-Ifconfig-Wrapper \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
