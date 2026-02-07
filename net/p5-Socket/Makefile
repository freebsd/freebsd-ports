PORTNAME=	Socket
PORTVERSION=	2.040
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Networking constants and support functions
WWW=		https://metacpan.org/release/Socket

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

PORTSCOUT=	limit:^[0-9\.]*$$

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Socket/Socket.so

.include <bsd.port.mk>
