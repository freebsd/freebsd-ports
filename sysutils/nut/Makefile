# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.exploits.org/nut/release/${PORTVERSION:R}/

MAINTAINER=	DougB@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/nut \
		--localstatedir=/var/db/nut \
		--with-drvpath=${PREFIX}/libexec/nut \
		--with-statepath=/var/db/nut \
		--with-altpidpath=/var/db/nut \
		--with-pidpath=/var/db/nut

MAN5=		ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5
MAN8=		apcsmart.8 bcmxcp.8 belkin.8 bestferrups801-807.8 \
		bestfortress.8 bestuferrups.8 bestups.8 cyberpower.8 etapro.8 \
		everups.8 fentonups.8 genericups.8 hp.8 isbmex.8 liebert.8 \
		masterguard.8 mge-ellipse.8 mge-utalk.8 microdowell.8 newapc.8 \
		nutupsdrv.8 oneac.8 powercom.8 powernet.8 sec.8 sms.8 \
		snmp-ups.8 tripplite.8 upsc.8 upscmd.8 upsd.8 upsdrvctl.8 \
		upslog.8 upsmon.8 upsrw.8 upssched.8 victronups.8

ALL_TARGET=	all

pre-fetch:
.if defined(CGI) && !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO_MSG} 'CGI clients are currently disabled because they require'
	@${ECHO_MSG} 'a later version of the gd2 library than we have.'
.endif

pre-install:
	@${MKDIR} ${PREFIX}/libexec/nut
	@${MKDIR} /var/db/nut
	@${CHOWN} uucp /var/db/nut

post-install:
	@${SED} -e "s#%%PREFIX%%#${PREFIX}#g" \
		${FILESDIR}/nut.sh.sample > ${PREFIX}/etc/rc.d/nut.sh.sample
	@${CHMOD} 0755 ${PREFIX}/etc/rc.d/nut.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/cables
	@${MKDIR} ${DOCSDIR}/drivers
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/drivers/*.txt ${DOCSDIR}/drivers
	${INSTALL_DATA} ${WRKSRC}/docs/drivers/README ${DOCSDIR}/drivers
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/driver.list ${DOCSDIR}
.for file in CHANGES CREDITS INSTALL NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
