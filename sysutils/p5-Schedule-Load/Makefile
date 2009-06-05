# New ports collection makefile for:	Schedule-Load
# Date created:		13 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Schedule-Load
PORTVERSION=	3.062
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Load distribution and status across multiple host machines

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		${SITE_PERL}/${PERL_ARCH}/Unix/Processors.pm:${PORTSDIR}/sysutils/p5-Unix-Processors \
		${SITE_PERL}/IPC/PidStat.pm:${PORTSDIR}/devel/p5-IPC-Locker \
		${SITE_PERL}/IPC/PidStat.pm:${PORTSDIR}/devel/p5-IPC-Locker \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes

MAN1=		rschedule.1 slchoosed.1 slpolice.1 slreportd.1 slrsh.1 \
		slchoosed_watchd.1
MAN3=		Schedule::Load.3 Schedule::Load::Chooser.3 \
		Schedule::Load::FakeReporter.3 Schedule::Load::Hold.3 \
		Schedule::Load::Hosts.3 Schedule::Load::Hosts::Host.3 \
		Schedule::Load::Hosts::Proc.3 Schedule::Load::Reporter.3 \
		Schedule::Load::ResourceReq.3 Schedule::Load::Safe.3 \
		Schedule::Load::Schedule.3 \
		Schedule::Load::Reporter::Disk.3 Schedule::Load::Reporter::Filesys.3 \
		Schedule::Load::Reporter::Network.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/init.d
	${INSTALL_SCRIPT} ${WRKSRC}/init.d/* ${EXAMPLESDIR}/init.d
.endif

.include <bsd.port.mk>
