# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WebService-Pushover
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to Pushover API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Moo>=0:devel/p5-Moo \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-URI>=0:net/p5-URI \
		p5-WebService-Simple>=0:www/p5-WebService-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Module-Build-Pluggable>=0.10:devel/p5-Module-Build-Pluggable \
		p5-Module-Build-Pluggable-ReadmeMarkdownFromPod>=0.04:devel/p5-Module-Build-Pluggable-ReadmeMarkdownFromPod
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Pod-Markdown>=0:textproc/p5-Pod-Markdown \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fake-HTTPD>=0:devel/p5-Test-Fake-HTTPD

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
