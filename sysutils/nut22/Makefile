# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	2.2.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.networkupstools.org/source/${PORTVERSION:R}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	Network UPS Tools

USE_AUTOTOOLS=	autoconf:261
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NUT_USER?=	uucp
NUT_GROUP?=	uucp
STATEDIR?=	/var/db/nut

OPTIONS=	USB		"USB support"	on \
		SNMP		"SNMP support"	on \
		IPV6		"IPV6 support"  on \
		LIBUPSCLIENT	"Include the libupsclient library"	off \
		CGI		"Web CGI interface"	off \

USE_RC_SUBR=	nut.sh nut_upsmon.sh nut_upslog.sh
SUB_LIST+=	STATEDIR=${STATEDIR}
PLIST_SUB+=	STATEDIR=${STATEDIR}

MAN5=		ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5
MAN8=		al175.8 apcsmart.8 bcmxcp.8 belkin.8 belkinunv.8 \
		bestuferrups.8 bestups.8 bestfcom.8 cpsups.8 cyberpower.8 \
		dummy-ups.8 etapro.8 everups.8 gamatronic.8 genericups.8 \
		isbmex.8 liebert.8 masterguard.8 megatec.8 metasys.8 \
		mge-shut.8 mge-utalk.8 nitram.8 nutupsdrv.8 oneac.8 optiups.8 \
		powercom.8 powerpanel.8 rhino.8 safenet.8 solis.8 tripplite.8 \
		tripplitesu.8 upsc.8 upscmd.8 upscode2.8 upsd.8 upsdrvctl.8 \
		upslog.8 upsmon.8 upsrw.8 upssched.8 victronups.8

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
		--with-linux-hiddev=no \
		--with-user=${NUT_USER} \
		--with-group=${NUT_GROUP}

.if defined(WITH_CGI)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
MAN5+=		hosts.conf.5 upsset.conf.5 upsstats.html.5
MAN8+=		upsset.cgi.8 upsstats.cgi.8 upsimage.cgi.8
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
WWWDIR?=	share/apache/htdocs
.else
CGIDIR?=	www/cgi-bin
WWWDIR?=	www/data
.endif
CONFIGURE_ARGS+=	--with-cgi --with-cgipath=${PREFIX}/${CGIDIR}/nut \
			--with-htmlpath=${PREFIX}/${WWWDIR}/nut \
			--with-gd-includes=-I${PREFIX}/include \
			--with-gd-libs="-L${PREFIX}/lib -lgd"
PLIST_SUB+=	NUT_CGI=""
PLIST_SUB+=	WWWDIR="${WWWDIR}"
PLIST_SUB+=	CGIDIR="${CGIDIR}"
PLIST_SUB+=	CGIETCDIR="etc/nut/"
.else
CONFIGURE_ARGS+=	--without-cgi
PLIST_SUB+=	NUT_CGI="@comment "
.endif

.if !defined(WITHOUT_USB)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=	--with-usb=auto
MAN8+=		bcmxcp_usb.8 megatec_usb.8 tripplite_usb.8 usbhid-ups.8
PLIST_SUB+=	NUT_USB=""
.else
CONFIGURE_ARGS+=	--without-usb
PLIST_SUB+=	NUT_USB="@comment "
.endif

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS+=	netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp
MAN8+=		snmp-ups.8
PLIST_SUB+=	NUT_SNMP=""
.else
CONFIGURE_ARGS+=	--without-snmp
PLIST_SUB+=	NUT_SNMP="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if defined(WITH_LIBUPSCLIENT)
CONFIGURE_ARGS+=	--with-lib --enable-pkg-config \
			--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig

MAN3+=		upscli_connect.3 upscli_disconnect.3 upscli_readline.3 \
		upscli_sendline.3 upscli_splitname.3 upscli_strerror.3

PLIST_SUB+=	NUT_LIB=""
.else
CONFIGURE_ARGS+=	--without-lib
PLIST_SUB+=	NUT_LIB="@comment "
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
