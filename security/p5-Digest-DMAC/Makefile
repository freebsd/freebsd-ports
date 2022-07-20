PORTNAME=	Digest-DMAC
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl5 interface to DMAC Double Message-Digest Algorithms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-CBC>=0:security/p5-Crypt-CBC

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
