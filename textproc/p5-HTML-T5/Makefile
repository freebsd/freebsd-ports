PORTNAME=	HTML-T5
PORTVERSION=	0.013
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML validation in a Perl object
WWW=		https://metacpan.org/dist/HTML-T5

LICENSE=	ART20

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		${RUN_DEPENDS}
LIB_DEPENDS=	libtidy5.so:www/tidy-html5
RUN_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTML-T5/T5.so

.include <bsd.port.mk>
