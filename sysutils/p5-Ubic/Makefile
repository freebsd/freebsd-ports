# New ports collection makefile for:	p5-Ubic
# Date created:		21 Sep 2011
# Whom:			Dmitry Yashin <dmitry@yashin.su>
#
# $FreeBSD$
#

PORTNAME=	Ubic
PORTVERSION=	1.34
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MMCLERIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@yashin.su
COMMENT=	Flexible perl-based service manager

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

LICENSE_FILES=	${WRKSRC}/LICENSE

PERL_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''

MAN1=		ubic.1 \
		ubic-admin.1 \
		ubic-daemon.1 \
		ubic-periodic.1 \
		ubic-update.1 \
		ubic-watchdog.1
MAN3=		Ubic.3 \
		Ubic::AccessGuard.3 \
		Ubic::Admin::Setup.3 \
		Ubic::AtomicFile.3 \
		Ubic::Cmd.3 \
		Ubic::Cmd::Results.3 \
		Ubic::Credentials.3 \
		Ubic::Credentials::OS::MacOSX.3 \
		Ubic::Credentials::OS::POSIX.3 \
		Ubic::Credentials::OS::Windows.3 \
		Ubic::Daemon.3 \
		Ubic::Daemon::OS.3 \
		Ubic::Daemon::OS::Linux.3 \
		Ubic::Daemon::OS::POSIX.3 \
		Ubic::Daemon::PidState.3 \
		Ubic::Daemon::Status.3 \
		Ubic::Lockf.3 \
		Ubic::Lockf::Alarm.3 \
		Ubic::Logger.3 \
		Ubic::Manual::FAQ.3 \
		Ubic::Manual::Intro.3 \
		Ubic::Manual::Multiservices.3 \
		Ubic::Manual::Overview.3 \
		Ubic::Multiservice.3 \
		Ubic::Multiservice::Dir.3 \
		Ubic::Multiservice::Simple.3 \
		Ubic::Persistent.3 \
		Ubic::Ping.3 \
		Ubic::Ping::Service.3 \
		Ubic::PortMap.3 \
		Ubic::Result.3 \
		Ubic::Result::Class.3 \
		Ubic::Run.3 \
		Ubic::Service.3 \
		Ubic::Service::Common.3 \
		Ubic::Service::SimpleDaemon.3 \
		Ubic::Service::Skeleton.3 \
		Ubic::Service::Utils.3 \
		Ubic::Settings.3 \
		Ubic::Settings::ConfigFile.3 \
		Ubic::SingletonLock.3 \
		Ubic::Watchdog.3

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/lib/Ubic/Admin/Setup.pm ${WRKSRC}/lib/Ubic/Settings.pm

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
