# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	Net-Dict
PORTVERSION=	2.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEILB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple client API for the DICT protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/&configure_testsuite/d; /EXE_FILES/d' ${WRKSRC}/Makefile.PL
	@${ECHO_CMD} '$$HOST = "test.dict.org"; $$PORT = 2628;' > ${WRKSRC}/t/test_host.cfg

.include <bsd.port.mk>
