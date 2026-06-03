PORTNAME=	YAML-Syck
PORTVERSION=	1.36
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast, lightweight YAML and JSON loader and dumper
WWW=		https://metacpan.org/release/YAML-Syck

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/YAML/Syck/Syck.so

.include <bsd.port.mk>
