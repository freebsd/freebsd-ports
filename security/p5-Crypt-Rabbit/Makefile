PORTNAME=	Crypt-Rabbit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for Rabbit stream cipher

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -i '' -e '/OPTIMIZE/s/=>.*/=> "${CFLAGS}",/g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
