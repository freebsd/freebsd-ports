# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	2.6.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.networkupstools.org/source/${PORTVERSION:R}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Network UPS Tools

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig

NUT_USER?=	uucp
NUT_GROUP?=	uucp
STATEDIR?=	/var/db/nut

OPTIONS_DEFINE=	SERIAL USB SNMP NEON PDU HAL CGI BASH
OPTIONS_DEFAULT=SERIAL USB SNMP NEON

SERIAL_DESC=	SERIAL support
USB_DESC=	USB support
SNMP_DESC=	SNMP support
NEON_DESC=	NEON XML/HTTP support
PDU_DESC=	Powerman PDU support
CGI_DESC=	Web CGI interface
BASH_DESC=	Bash Completion support

USE_RC_SUBR=	nut nut_upsmon nut_upslog
SUB_LIST+=	STATEDIR=${STATEDIR}
PLIST_SUB+=	STATEDIR=${STATEDIR}

MAN3=		nutscan.3 nutscan_add_device_to_device.3 \
		nutscan_add_option_to_device.3 nutscan_cidr_to_ip.3 \
		nutscan_display_parsable.3 nutscan_display_ups_conf.3 \
		nutscan_free_device.3 nutscan_init.3 nutscan_new_device.3 \
		nutscan_scan_avahi.3 nutscan_scan_ipmi.3 nutscan_scan_nut.3 \
		nutscan_scan_snmp.3 nutscan_scan_usb.3 nutscan_scan_xml_http.3 \
		upscli_connect.3 upscli_disconnect.3 upscli_fd.3 \
		upscli_get.3 upscli_list_next.3 upscli_list_start.3 \
		upscli_readline.3 upscli_sendline.3 upscli_splitaddr.3 \
		upscli_splitname.3 upscli_ssl.3 upscli_strerror.3 \
		upscli_upserror.3 upsclient.3

MAN5=		nut.conf.5 ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5

MAN8=		apcsmart-old.8 nut-recorder.8 nut-scanner.8 nutupsdrv.8 upsc.8 \
		upscmd.8 upsd.8 upsdrvctl.8 upslog.8 upsmon.8 upsrw.8 upssched.8

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
		--with-user=${NUT_USER} \
		--with-group=${NUT_GROUP} \
		--with-dev

.if ${PORT_OPTIONS:MCGI}
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
MAN5+=		hosts.conf.5 upsset.conf.5 upsstats.html.5
MAN8+=		upsset.cgi.8 upsstats.cgi.8 upsimage.cgi.8
CGIDIR?=	${PREFIX}/www/cgi-bin/${PORTNAME}
CGIDIR_REL?=	${CGIDIR:S,^${PREFIX}/,,}
CONFIGURE_ARGS+=	--with-cgi --with-cgipath=${CGIDIR} \
			--with-htmlpath=${WWWDIR} \
			--with-gd-includes=-I${LOCALBASE}/include \
			--with-gd-libs="-L${LOCALBASE}/lib -lgd"
PLIST_SUB+=	NUT_CGI=""
PLIST_SUB+=	CGIDIR="${CGIDIR_REL}"
PLIST_SUB+=	CGIETCDIR="etc/nut/"
.else
CONFIGURE_ARGS+=	--without-cgi
PLIST_SUB+=	NUT_CGI="@comment "
.endif

.if ${PORT_OPTIONS:MSERIAL}
CONFIGURE_ARGS+=	--with-serial
MAN8+=		apcsmart.8 bestfortress.8 bcmxcp.8 belkin.8 belkinunv.8 \
		bestuferrups.8 bestups.8 bestfcom.8 blazer.8 clone.8 \
		dummy-ups.8 etapro.8 everups.8 gamatronic.8 genericups.8 \
		isbmex.8 ivtscd.8 liebert.8 liebert-esp2.8 masterguard.8 \
		metasys.8 mge-shut.8 mge-utalk.8 microdowell.8 oneac.8 \
		optiups.8 powercom.8 powerpanel.8 rhino.8 safenet.8 solis.8 \
		tripplite.8 tripplitesu.8 upscode2.8 victronups.8
PLIST_SUB+=	NUT_SERIAL=""
.else
CONFIGURE_ARGS+=	--without-serial
PLIST_SUB+=	NUT_SERIAL="@comment "
.endif

.if ${PORT_OPTIONS:MUSB}
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
. else
#EXTRA_PATCHES=	${FILESDIR}/extra-patch-m4_nut_check_libusb.m4
. endif
CONFIGURE_ARGS+=	--with-usb=auto
MAN8+=		bcmxcp_usb.8 richcomm_usb.8 tripplite_usb.8 usbhid-ups.8
PLIST_SUB+=	NUT_USB=""
.else
CONFIGURE_ARGS+=	--without-usb
PLIST_SUB+=	NUT_USB="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp
MAN8+=		snmp-ups.8
PLIST_SUB+=	NUT_SNMP=""
.else
CONFIGURE_ARGS+=	--without-snmp
PLIST_SUB+=	NUT_SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MNEON}
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
CONFIGURE_ARGS+=	--with-neonxml
MAN8+=		netxml-ups.8
PLIST_SUB+=	NUT_NEON=""
.else
CONFIGURE_ARGS+=	--without-neonxml
PLIST_SUB+=	NUT_NEON="@comment "
.endif

.if ${PORT_OPTIONS:MPDU}
LIB_DEPENDS+=	powerman.0:${PORTSDIR}/sysutils/powerman
CONFIGURE_ARGS+=	--with-powerman
MAN8+=		powerman-pdu.8
PLIST_SUB+=	NUT_PDU=""
.else
CONFIGURE_ARGS+=	--without-powerman
PLIST_SUB+=	NUT_PDU="@comment "
.endif

.if ${PORT_OPTIONS:MHAL}
. if empty(PORT_OPTIONS:MUSB)
BROKEN=		HAL is only usable with USB support enabled. Run 'make config' again!
. endif
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--with-hal \
			--with-hal-callouts-path=${PREFIX}/libexec
#MAN8+=
PLIST_SUB+=	NUT_HAL=""
.else
CONFIGURE_ARGS+=	--without-hal
PLIST_SUB+=	NUT_HAL="@comment "
.endif

.if ${PORT_OPTIONS:MBASH}
RUN_DEPENDS+=	${LOCALBASE}/bin/bash_completion.sh:${PORTSDIR}/shells/bash-completion
PLIST_SUB+=	BASH=""
.else
PLIST_SUB+=	BASH="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<hal/|<|' ${WRKSRC}/drivers/main-hal.c ${WRKSRC}/drivers/dstate-hal.c ${WRKSRC}/drivers/dstate-hal.h
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share| ; s|$${datarootdir}|${PREFIX}/share|' ${WRKSRC}/m4/nut_check_libhal.m4

pre-install:
	@${MKDIR} ${PREFIX}/libexec/nut
	@${MKDIR} ${STATEDIR}
	@${CHOWN} ${NUT_USER}:${NUT_GROUP} ${STATEDIR}
	@${CHMOD} 0750 ${STATEDIR}

.if !defined(NOPORTDOCS)
post-install:
.if ${PORT_OPTIONS:MBASH}
	@${MKDIR} ${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/scripts/misc/nut.bash_completion ${PREFIX}/etc/bash_completion.d/
.endif
	@${MKDIR} ${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ.txt ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog INSTALL MAINTAINERS NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
