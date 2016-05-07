# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	apcupsd
PORTVERSION=	3.14.13
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20Stable/${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Set of programs for controlling APC UPS

LICENSE=	GPLv2

USE_RC_SUBR=	apcupsd
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USES=		gmake
OPTIONS_SUB=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/sbin \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${ETCDIR} \
		--with-serial-dev=/dev/usv

CONFIGURE_ENV+=	LD="${CXX}" \
		ac_cv_path_SHUTDOWN="/sbin/shutdown"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	APCSMART_DRV APCDUMB_DRV CLIENT_ONLY CGI PCNET_DRV USB SNMP_DRV \
		SNMP_DRV_OLD TCP_WRAPPERS TEST_DRV GAPCMON DOCS MODBUS
OPTIONS_DEFAULT=	APCSMART_DRV APCDUMB_DRV PCNET_DRV USB TCP_WRAPPERS MODBUS
APCSMART_DRV_DESC=	Compile APC SmartUPS serial driver
APCDUMB_DRV_DESC=	Compile dumb UPS driver
CLIENT_ONLY_DESC=	Only NIS client (no network server or drivers)
CGI_DESC=		Compile with CGI programms to show status
PCNET_DRV_DESC=		Compile PowerChute Network Shutdown driver
USB_DESC=		Compile with USB Support driver
SNMP_DRV_DESC=		Compile with SNMP driver
SNMP_DRV_OLD_DESC=	Compile with old SNMP driver
TCP_WRAPPERS_DESC=	Compile with TCP_WRAPPERS support
TEST_DRV_DESC=		Compile TEST driver
GAPCMON_DESC=		Build GTK GUI front-end
MODBUS_DESC=		Compile with MODBUS driver

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
GAPCMON_USE=			GNOME=gconf2
GAPCMON_CONFLICTS=		gapcmon-[0-9]*
PCNET_DRV_CONFIGURE_ENABLE=	pcnet
USB_CONFIGURE_ENABLE=		usb
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
	${PORT_OPTIONS:MUSB} || \
	${PORT_OPTIONS:MSNMP_DRV} || ${PORT_OPTIONS:MTEST_DRV} )
	@${ECHO_CMD} "It doesn't make sense to build drivers if all you want is"
	@${ECHO_CMD} "the client; please do make config and select either"
	@${ECHO_CMD} "CLIENT_ONLY or the *_DRV you need"
	@${FALSE}
.endif

post-install:
	@${ECHO_CMD} "@unexec if [ -d %D/${ETCDIR_REL} ]; then ${ECHO_CMD} \"If you are permanently removing this port, you should do a ``rm -rf ${ETCDIR}`` to remove config files left.\" | ${FMT} ; fi" >> ${TMPPLIST}
#	Install sample startup script
	for na in apcupsd.conf apcupsd.css hosts.conf multimon.conf; do \
		if [ -f ${STAGEDIR}${ETCDIR}/$$na ]; then \
			${MV} ${STAGEDIR}${ETCDIR}/$$na ${STAGEDIR}${ETCDIR}/$$na.sample; \
		fi \
	done

.include <bsd.port.mk>
