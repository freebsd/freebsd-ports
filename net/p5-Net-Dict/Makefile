# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	Net-Dict
PORTVERSION=	2.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple client API for the DICT protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Differences>=0.620:devel/p5-Test-Differences \
		p5-Test-RequiresInternet>=0.05:devel/p5-Test-RequiresInternet

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL
	@${ECHO_CMD} '$$HOST = "test.dict.org"; $$PORT = 2628;' > ${WRKSRC}/t/test_host.cfg

.include <bsd.port.mk>
