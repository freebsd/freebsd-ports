# New ports collection makefile for:	Schedule-Load
# Date created:		13 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Schedule-Load
PORTVERSION=	3.064
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load distribution and status across multiple host machines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Proc-ProcessTable>=0.40:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Unix-Processors>=2.02:${PORTSDIR}/sysutils/p5-Unix-Processors \
		p5-IPC-Locker>=1.41:${PORTSDIR}/devel/p5-IPC-Locker
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
