# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://us1.networkupstools.org/source/${PORTVERSION:R}/ \
		http://eu1.networkupstools.org/source/${PORTVERSION:R}/

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Network UPS Tools

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/nut \
		--localstatedir=/var/db/nut \
		--datadir=${PREFIX}/etc/nut \
		--with-drvpath=${PREFIX}/libexec/nut \
		--with-statepath=/var/db/nut \
		--with-altpidpath=/var/db/nut \
		--with-pidpath=/var/db/nut

MAN5=		ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5
MAN8=		apcsmart.8 belkin.8 belkinunv.8 bestuferrups.8 bestups.8 \
		cyberpower.8 cyberpower1100.8 etapro.8 everups.8 \
		fentonups.8 genericups.8 ippon.8 isbmex.8 liebert.8 \
		masterguard.8 mge-shut.8 mge-utalk.8 nutupsdrv.8 oneac.8 \
		powercom.8 sms.8 snmp-ups.8 tripplite.8 tripplitesu.8 \
		upsc.8 upscmd.8 upsd.8 upsdrvctl.8 upslog.8 upsmon.8 \
		upsrw.8 upssched.8 victronups.8 safenet.8

ALL_TARGET=	all
INSTALL_TARGET=	install install-conf

.if defined(WITH_NUT_CGI)
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
ALL_TARGET+=	cgi
INSTALL_TARGET+=install-cgi install-cgi-conf
MAN5+=		hosts.conf.5 upsset.conf.5 upsstats.html.5
MAN8+=		upsset.cgi.8 upsstats.cgi.8 upsimage.cgi.8
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
CONFIGURE_ARGS+=	--with-cgi --with-cgipath=${PREFIX}/${CGIDIR}/nut \
			--with-gd-includes=-I${PREFIX}/include \
			--with-gd-libs="-L${PREFIX}/lib -lgd"
PLIST_SUB+=	CGIFILES="${CGIDIR}/nut/"
PLIST_SUB+=	CGIDIRRM="@dirrm ${CGIDIR}/nut"
PLIST_SUB+=	CGIETC="etc/nut/"
.else
PLIST_SUB+=	CGIFILES="@comment "
PLIST_SUB+=	CGIDIRRM="@comment "
PLIST_SUB+=	CGIETC="@comment "
.endif

pre-install:
.if !defined(WITH_NUT_CGI) && !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO_MSG} "Type \"make -DWITH_NUT_CGI\" if you want to build CGI scripts."
.endif
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
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
.for file in CHANGES CREDITS INSTALL NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
