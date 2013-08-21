# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Monitor-Simple
PORTVERSION=	0.2.8
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple monitoring of applications and services

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-CaptureOutput>=0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which

USE_PERL5=	configure
USES=		perl5

MAN1=		smonitor.1
MAN3=		Monitor::Simple.3 \
		Monitor::Simple::Config.3 \
		Monitor::Simple::Log.3 \
		Monitor::Simple::Notifier.3 \
		Monitor::Simple::Output.3 \
		Monitor::Simple::UserAgent.3 \
		Monitor::Simple::Utils.3

.include <bsd.port.mk>
