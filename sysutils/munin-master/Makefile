# New ports collection makefile for:	munin-master
# Date created:				25 Januar 2004
# Whom:					Lupe Christoph <lupe@lupe-christoph.de>
#
# $FreeBSD$
#

PORTNAME=	munin
PORTVERSION=	1.4.4
CATEGORIES=	sysutils perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}
PKGNAMESUFFIX=	-master

MAINTAINER=	des@FreeBSD.org
COMMENT=	Collector part of Munin

BUILD_DEPENDS=	${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/Munin/Common/Defaults.pm:${PORTSDIR}/sysutils/munin-common \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/converters/p5-Storable-AMF \
		${SITE_PERL}/DateTime/HiRes.pm:${PORTSDIR}/devel/p5-DateTime-HiRes \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	${SITE_PERL}/Munin/Common/Defaults.pm:${PORTSDIR}/sysutils/munin-common \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/converters/p5-Storable-AMF \
		${SITE_PERL}/DateTime/HiRes.pm:${PORTSDIR}/devel/p5-DateTime-HiRes \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced

USE_PERL5=	yes
USE_GMAKE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

.include "${.CURDIR}/../munin-common/munin.mk"

ALL_TARGET=	build-master build-man
INSTALL_TARGET=	install-master-prime

MAN3=		Munin::Master::Config.3 \
		Munin::Master::Group.3 \
		Munin::Master::GroupRepository.3 \
		Munin::Master::HTMLOld.3 \
		Munin::Master::Host.3 \
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

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@${CHOWN} ${USERS}:${GROUPS} ${DBDIR} ${STATEDIR} ${WWWDIR}
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

.include <bsd.port.mk>
