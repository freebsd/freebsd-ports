# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Monitor-Simple
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple monitoring of applications and services

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-CaptureOutput>=0:devel/p5-IO-CaptureOutput \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-File-Which>=0:sysutils/p5-File-Which

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
