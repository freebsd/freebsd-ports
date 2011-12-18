# New ports collection makefile for:   p5-Net-Dict
# Date created:                21 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Dict
PORTVERSION=	2.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEILB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A simple client API for the DICT protocol

PERL_CONFIGURE=	yes

MAN3=		Net::Dict.3

post-patch:
	@${REINPLACE_CMD} -e '/&configure_testsuite/d; /EXE_FILES/d' ${WRKSRC}/Makefile.PL
	@${ECHO_CMD} '$$HOST = "test.dict.org"; $$PORT = 2628;' > ${WRKSRC}/t/test_host.cfg

.include <bsd.port.mk>
