# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-WikiDoc
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate Pod from inline wiki style text

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Getopt-Lucid>=0.14:textproc/p5-Getopt-Lucid \
		p5-IO-String>=1.06:devel/p5-IO-String \
		p5-Parse-RecDescent>=1.967.006:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IPC-Run3>=0.033:devel/p5-IPC-Run3 \
		p5-Probe-Perl>=0.01:sysutils/p5-Probe-Perl

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
