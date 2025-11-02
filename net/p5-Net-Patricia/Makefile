PORTNAME=	Net-Patricia
PORTVERSION=	1.24
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fast IP address lookups
WWW=		https://metacpan.org/release/Net-Patricia

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-CIDR-Lite>=0.20:net/p5-Net-CIDR-Lite \
		p5-Socket6>=0:net/p5-Socket6

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Patricia/Patricia.so

.include <bsd.port.mk>
