PORTNAME=	Email-LocalDelivery
PORTVERSION=	1.201
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Deliver a piece of email - simply

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-FolderType>=0.700:mail/p5-Email-FolderType \
		p5-Email-Simple>=1.998:mail/p5-Email-Simple \
		p5-File-Path-Expand>=1.01:devel/p5-File-Path-Expand

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
