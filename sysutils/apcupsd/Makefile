# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	apcupsd
PORTVERSION=	3.14.14
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20Stable/${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Set of programs for controlling APC UPS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/sbin \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${ETCDIR} \
		--with-serial-dev=/dev/usv

CONFIGURE_ENV+=	LD="${CXX}" \
		ac_cv_path_SHUTDOWN="/sbin/shutdown"

USE_RC_SUBR=	apcupsd
SUB_FILES=	pkg-message

CONFLICTS_INSTALL=	apcctrl

OPTIONS_DEFINE=	APCDUMB_DRV APCSMART_DRV CGI CLIENT_ONLY GAPCMON MODBUS \
		MODBUS_USB PCNET_DRV SHUTDOWN_POWEROFF SNMP_DRV SNMP_DRV_OLD \
		TCP_WRAPPERS TEST_DRV USB_DRV
OPTIONS_DEFAULT=	APCDUMB_DRV APCSMART_DRV MODBUS MODBUS_USB PCNET_DRV \
		SNMP_DRV TCP_WRAPPERS USB_DRV
OPTIONS_SUB=	yes

APCDUMB_DRV_DESC=	Dumb UPS driver support
APCSMART_DRV_DESC=	APC SmartUPS serial driver support
CGI_DESC=		Build CGI programs to show status
CLIENT_ONLY_DESC=	Only NIS client (no network server or drivers)
GAPCMON_DESC=		Build GTK GUI front-end
MODBUS_DESC=		MODBUS driver support
MODBUS_USB_DESC=	MODBUS USB driver support
PCNET_DRV_DESC=		PowerChute Network Shutdown driver support
SHUTDOWN_POWEROFF_DESC=	Shutdown behavior with Halt and Power off
SNMP_DRV_DESC=		SNMP driver support
SNMP_DRV_OLD_DESC=	Old SNMP driver support
TCP_WRAPPERS_DESC=	${LIBWRAP_DESC}
TEST_DRV_DESC=		Test driver support
USB_DRV_DESC=		USB driver support

APCDUMB_DRV_CONFIGURE_ENABLE=	dumb
APCSMART_DRV_CONFIGURE_ENABLE=	apcsmart
CGI_CONFIGURE_ENABLE=		cgi
CGI_CONFIGURE_ON=		--with-cgi-bin=${ETCDIR}/cgi
CGI_LIB_DEPENDS=		libgd.so:graphics/gd
CLIENT_ONLY_CONFIGURE_ON=	--enable-net \
				--disable-apcsmart --disable-dumb --disable-usb \
				--disable-snmp --disable-test --disable-pcnet
GAPCMON_CONFIGURE_ENABLE=	gapcmon
GAPCMON_USES=			gnome pkgconfig xorg
GAPCMON_USE=			GNOME=cairo,gconf2,gdkpixbuf2 XORG=x11,xext
GAPCMON_LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
				libfreetype.so:print/freetype2
GAPCMON_CONFLICTS=		gapcmon
MODBUS_CONFIGURE_ENABLE=	modbus
MODBUS_USB_CONFIGURE_ENABLE=	modbus-usb
PCNET_DRV_CONFIGURE_ENABLE=	pcnet
SNMP_DRV_CONFIGURE_ENABLE=	snmp
SNMP_DRV_OLD_CONFIGURE_ENABLE=	net-snmp
SNMP_DRV_OLD_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
TCP_WRAPPERS_CONFIGURE_WITH=	libwrap=yes
TEST_DRV_CONFIGURE_ENABLE=	test
USB_DRV_CONFIGURE_ENABLE=	usb

.include <bsd.port.options.mk>

post-patch-SHUTDOWN_POWEROFF-on:
	${REINPLACE_CMD} -e 's|-h now|-p now|' \
		${WRKSRC}/platforms/freebsd/apccontrol.in

pre-configure:
.if ${PORT_OPTIONS:MCLIENT_ONLY} && ( ${PORT_OPTIONS:MAPCSMART_DRV} || \
	${PORT_OPTIONS:MAPCDUMB_DRV} || ${PORT_OPTIONS:MPCNET_DRV} || \
	${PORT_OPTIONS:MUSB_DRV} || \
	${PORT_OPTIONS:MSNMP_DRV} || ${PORT_OPTIONS:MTEST_DRV} )
	@${ECHO_CMD} "It doesn't make sense to build drivers if all you want is"
	@${ECHO_CMD} "the client; please do make config and select either"
	@${ECHO_CMD} "CLIENT_ONLY or the *_DRV you need"
	@${FALSE}
.endif

.include <bsd.port.mk>
