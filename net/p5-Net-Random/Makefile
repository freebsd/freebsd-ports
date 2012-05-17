# New ports collection makefile for:	p5-Net-Random
# Date created:				Wed Dec 14 11:40:50 CST 2005
# Whom:	      				clsung
#
# $FreeBSD$
#

PORTNAME=	Net-Random
PORTVERSION=	2.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DCANTRELL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl5 module to get random data from online sources

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

PERL_CONFIGURE=	YES

MAN3=		Net::Random.3

.include <bsd.port.mk>
