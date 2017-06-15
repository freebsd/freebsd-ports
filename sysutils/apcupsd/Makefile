# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	apcupsd
PORTVERSION=	3.14.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20Stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of programs for controlling APC UPS

LICENSE=	GPLv2

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

OPTIONS_DEFINE=	APCSMART_DRV APCDUMB_DRV CLIENT_ONLY CGI PCNET_DRV USB_DRV \
		SNMP_DRV SNMP_DRV_OLD TCP_WRAPPERS TEST_DRV GAPCMON \
		DOCS MODBUS
OPTIONS_DEFAULT=	APCSMART_DRV APCDUMB_DRV PCNET_DRV SNMP_DRV USB_DRV \
		TCP_WRAPPERS MODBUS
OPTIONS_SUB=	yes

APCSMART_DRV_DESC=	APC SmartUPS serial driver support
APCDUMB_DRV_DESC=	Dumb UPS driver support
CLIENT_ONLY_DESC=	Only NIS client (no network server or drivers)
CGI_DESC=		Build CGI programs to show status
PCNET_DRV_DESC=		PowerChute Network Shutdown driver support
USB_DRV_DESC=		USB driver support
SNMP_DRV_DESC=		SNMP driver support
SNMP_DRV_OLD_DESC=	Old SNMP driver support
TCP_WRAPPERS_DESC=	${LIBWRAP_DESC}
TEST_DRV_DESC=		Test driver support
GAPCMON_DESC=		Build GTK GUI front-end
MODBUS_DESC=		MODBUS driver support

#PORTDOCS=	${PORTNAME}.pdf

APCSMART_DRV_CONFIGURE_ENABLE=	apcsmart
APCDUMB_DRV_CONFIGURE_ENABLE=	dumb
CLIENT_ONLY_CONFIGURE_ON=	--enable-net \
				--disable-apcsmart --disable-dumb --disable-usb \
				--disable-snmp --disable-test --disable-pcnet
CGI_CONFIGURE_ENABLE=		cgi
CGI_CONFIGURE_ON=		--with-cgi-bin=${ETCDIR}/cgi
CGI_LIB_DEPENDS=		libgd.so:graphics/gd
GAPCMON_CONFIGURE_ENABLE=	gapcmon
GAPCMON_USES=			pkgconfig
GAPCMON_USE=			GNOME=gconf2
GAPCMON_CONFLICTS=		gapcmon-[0-9]*
PCNET_DRV_CONFIGURE_ENABLE=	pcnet
USB_DRV_CONFIGURE_ENABLE=	usb
SNMP_DRV_CONFIGURE_ENABLE=	snmp
MODBUS_CONFIGURE_ENABLE=	modbus
SNMP_DRV_OLD_CONFIGURE_ENABLE=	net-snmp
SNMP_DRV_OLD_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
TCP_WRAPPERS_CONFIGURE_WITH=	libwrap=yes
TEST_DRV_CONFIGURE_ENABLE=	test

#CONFIGURE_ARGS+=	--with-libwrap=yes
#CONFIGURE_ENV+=		LIBS="-lcurses -lmenu"
#PLIST_SUB+=		POWERFL=""

.include <bsd.port.options.mk>

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
