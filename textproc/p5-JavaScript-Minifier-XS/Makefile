PORTNAME=	JavaScript-Minifier-XS
PORTVERSION=	0.16
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GTERMARS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS based JavaScript minifier
WWW=		https://metacpan.org/release/JavaScript-Minifier-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-DiagINC>=0.002:devel/p5-Test-DiagINC

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/JavaScript/Minifier/XS/XS.so

.include <bsd.port.mk>
