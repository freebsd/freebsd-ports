# Created by: Lupe Christoph <lupe@lupe-christoph.de>
# $FreeBSD$

PORTNAME=	munin
PORTVERSION=	${MUNIN_VERSION}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MUNIN_SITES}
PKGNAMESUFFIX=	-master

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collector part of Munin

BUILD_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI

USES=		gmake perl5

PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include "${.CURDIR}/../munin-common/munin.mk"

EXTRA_PATCHES=	${MUNIN_PATCHES}
DISTINFO_FILE=	${MUNIN_DISTINFO}
ALL_TARGET=	infiles build-master build-man
INSTALL_TARGET=	install-master-prime

MAN3=		Munin::Master::Config.3 \
		Munin::Master::Group.3 \
		Munin::Master::GroupRepository.3 \
		Munin::Master::HTMLOld.3 \
		Munin::Master::Host.3 \
		Munin::Master::LimitsOld.3 \
		Munin::Master::Logger.3 \
		Munin::Master::Node.3 \
		Munin::Master::ProcessManager.3 \
		Munin::Master::Update.3 \
		Munin::Master::UpdateWorker.3 \
		Munin::Master::Utils.3 \
		Munin::Master::Worker.3
MAN5=		munin.conf.5
MAN8=		munin-cron.8 \
		munin-graph.8 \
		munin-html.8 \
		munin-limits.8 \
		munin-update.8

PLIST_SUB=	DBDIR=${DBDIR}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@${CHOWN} ${USERS}:${GROUPS} ${DBDIR} ${STATEDIR} ${WWWDIR}
	@${CHOWN} ${WWWOWN} ${DBDIR}/cgi-tmp
	@${INSTALL_DATA} ${WRKSRC}/build/master/munin.conf \
		${PREFIX}/etc/munin/munin.conf.sample
	@(cd ${WRKSRC}/master/blib/libdoc && for man in ${MAN3}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man3; \
	done)
	@(cd ${WRKSRC}/build/doc && for man in ${MAN5}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man5; \
	done)
	@(cd ${WRKSRC}/build/doc && for man in ${MAN8}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man8; \
	done)
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
