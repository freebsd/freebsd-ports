# New ports collection makefile for:	p5-Monitor-Simple
# Date created:		2011-10-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Monitor-Simple
PORTVERSION=	0.2.4
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple monitoring of applications and services

BUILD_DEPENDS=	p5-IO-CaptureOutput>=0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-IO-CaptureOutput>=0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp

PERL_CONFIGURE=	yes

MAN1=		smonitor.1
MAN3=		Monitor::Simple.3 \
		Monitor::Simple::Config.3 \
		Monitor::Simple::Log.3 \
		Monitor::Simple::Notifier.3 \
		Monitor::Simple::Output.3 \
		Monitor::Simple::UserAgent.3 \
		Monitor::Simple::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Getopt-Long>=2.38:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS+=	p5-Getopt-Long>=2.38:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.include <bsd.port.post.mk>
