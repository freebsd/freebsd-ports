# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.networkupstools.org/source/${PORTVERSION:R}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network UPS Tools

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig

NO_LATEST_LINK=	yes

NUT_USER?=	uucp
NUT_GROUP?=	uucp
STATEDIR?=	/var/db/nut

OPTIONS=	SERIAL		"SERIAL support"	on \
		USB		"USB support"	on \
		SNMP		"SNMP support"	on \
		NEON		"NEON XML/HTTP support"	on \
		HAL		"HAL support"	off \
		IPV6		"IPV6 support"  on \
		DEVEL		"Install header files"	off \
		CGI		"Web CGI interface"	off \

USE_RC_SUBR=	nut.sh nut_upsmon.sh nut_upslog.sh
SUB_LIST+=	STATEDIR=${STATEDIR}
PLIST_SUB+=	STATEDIR=${STATEDIR}

MAN5=		ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5

MAN8=		nutupsdrv.8 upsc.8 upscmd.8 upsd.8 upsdrvctl.8 \
		upslog.8 upsmon.8 upsrw.8 upssched.8

PORTDOCS=	*

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/nut \
		--program-transform-name="" \
		--localstatedir=${STATEDIR} \
		--datadir=${PREFIX}/etc/nut \
		--with-drvpath=${PREFIX}/libexec/nut \
		--with-statepath=${STATEDIR} \
		--with-altpidpath=${STATEDIR} \
		--with-pidpath=${STATEDIR} \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
		--with-linux-hiddev=no \
		--with-user=${NUT_USER} \
		--with-group=${NUT_GROUP}

.if defined(WITH_CGI)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
MAN5+=		hosts.conf.5 upsset.conf.5 upsstats.html.5
MAN8+=		upsset.cgi.8 upsstats.cgi.8 upsimage.cgi.8
CGIDIR?=	${PREFIX}/www/cgi-bin/${PORTNAME}
CGIDIR_REL?=	${CGIDIR:S,^${PREFIX}/,,}
CONFIGURE_ARGS+=	--with-cgi --with-cgipath=${CGIDIR} \
			--with-htmlpath=${WWWDIR} \
			--with-gd-includes=-I${PREFIX}/include \
			--with-gd-libs="-L${PREFIX}/lib -lgd"
PLIST_SUB+=	NUT_CGI=""
PLIST_SUB+=	CGIDIR="${CGIDIR_REL}"
PLIST_SUB+=	CGIETCDIR="etc/nut/"
.else
CONFIGURE_ARGS+=	--without-cgi
PLIST_SUB+=	NUT_CGI="@comment "
.endif

.if !defined(WITHOUT_SERIAL)
CONFIGURE_ARGS+=	--with-serial
MAN8+=		al175.8 apcsmart.8 bcmxcp.8 belkin.8 belkinunv.8 \
		bestuferrups.8 bestups.8 bestfcom.8 cpsups.8 cyberpower.8 \
		dummy-ups.8 etapro.8 everups.8 gamatronic.8 genericups.8 \
		isbmex.8 liebert.8 masterguard.8 megatec.8 metasys.8 \
		mge-shut.8 mge-utalk.8 nitram.8 oneac.8 optiups.8 \
		powercom.8 powerpanel.8 rhino.8 safenet.8 solis.8 tripplite.8 \
		tripplitesu.8 upscode2.8 victronups.8
PLIST_SUB+=	NUT_SERIAL=""
.else
CONFIGURE_ARGS+=	--without-serial
PLIST_SUB+=	NUT_SERIAL="@comment "
.endif

.if !defined(WITHOUT_USB)
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
. else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-m4_nut_check_libusb.m4
. endif
CONFIGURE_ARGS+=	--with-usb=auto
MAN8+=		bcmxcp_usb.8 megatec_usb.8 tripplite_usb.8 usbhid-ups.8
PLIST_SUB+=	NUT_USB=""
.else
CONFIGURE_ARGS+=	--without-usb
PLIST_SUB+=	NUT_USB="@comment "
.endif

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS+=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp
MAN8+=		snmp-ups.8
PLIST_SUB+=	NUT_SNMP=""
.else
CONFIGURE_ARGS+=	--without-snmp
PLIST_SUB+=	NUT_SNMP="@comment "
.endif

.if !defined(WITHOUT_NEON)
LIB_DEPENDS+=	neon.28:${PORTSDIR}/www/neon28
CONFIGURE_ARGS+=	--with-neonxml
MAN8+=		netxml-ups.8
PLIST_SUB+=	NUT_NEON=""
.else
CONFIGURE_ARGS+=	--without-neonxml
PLIST_SUB+=	NUT_NEON="@comment "
.endif

.if defined(WITH_HAL)
. if defined(WITHOUT_USB)
BROKEN=		HAL is only usable with USB support enabled. Run 'make config' again!
. endif
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--with-hal
#MAN8+=
PLIST_SUB+=	NUT_HAL=""
.else
CONFIGURE_ARGS+=	--without-hal
PLIST_SUB+=	NUT_HAL="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if defined(WITH_DEVEL)
CONFIGURE_ARGS+=	--with-dev
MAN3+=		upscli_connect.3 upscli_disconnect.3 upscli_fd.3 \
		upscli_get.3 upscli_list_next.3 upscli_list_start.3 \
		upscli_readline.3 upscli_sendline.3 upscli_splitaddr.3 \
		upscli_splitname.3 upscli_ssl.3 upscli_strerror.3 \
		upscli_upserror.3 upsclient.3

PLIST_SUB+=	NUT_DEVEL=""
.else
CONFIGURE_ARGS+=	--without-dev
PLIST_SUB+=	NUT_DEVEL="@comment "
.endif

pre-install:
	@${MKDIR} ${PREFIX}/libexec/nut
	@${MKDIR} ${STATEDIR}
	@${CHOWN} ${NUT_USER}:${NUT_GROUP} ${STATEDIR}
	@${CHMOD} 0750 ${STATEDIR}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog INSTALL MAINTAINERS NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
