# $FreeBSD$

PORTNAME=	Pod-Site
PORTVERSION=	0.56
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build browsable HTML documentation for your app

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Object-Tiny>=0:devel/p5-Object-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-File>=0:devel/p5-Test-File \
		p5-Test-MockModule>=0.05:devel/p5-Test-MockModule \
		p5-Test-XPath>=0.12:lang/p5-Test-XPath

OPTIONS_DEFINE=	PODT

PODT_DESC=	Include Pod package tests

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPODT}
TEST_DEPENDS+=	p5-Test-Pod>=1.41:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.06:devel/p5-Test-Pod-Coverage
.endif

.include <bsd.port.mk>
