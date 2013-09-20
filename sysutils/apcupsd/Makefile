# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	apcupsd
PORTVERSION=	3.14.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20Stable/${PORTVERSION}:src_sf \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/:src_bk \
		http://apcupsd.sourceforge.net/manual/:doc_sf \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/:doc_bk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src_sf,src_bk \
		${PORTNAME}.pdf:doc_sf,doc_bk
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Set of programs for controlling APC UPS

IGNOREFILES=	${PORTNAME}.pdf

USE_RC_SUBR=	apcupsd
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/sbin \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${ETCDIR} \
		--with-serial-dev=/dev/usv

CONFIGURE_ENV+= LD="${CXX}" 
#CONFIGURE_ENV+=	LIBS="-lstdc++"
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAN5=		apcupsd.conf.5
MAN8=		apcaccess.8 apccontrol.8 apctest.8 apcupsd.8

OPTIONS_DEFINE=	APCSMART_DRV APCDUMB_DRV CLIENT_ONLY CGI PCNET_DRV USB SNMP_DRV \
		SNMP_DRV_OLD TCP_WRAPPERS TEST_DRV GAPCMON DOCS
OPTIONS_DEFAULT=	APCSMART_DRV APCDUMB_DRV PCNET_DRV USB TCP_WRAPPERS
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

PORTDOCS=	${PORTNAME}.pdf

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPCSMART_DRV}
CONFIGURE_ARGS+=	--enable-apcsmart
.else
CONFIGURE_ARGS+=	--disable-apcsmart
.endif

.if ${PORT_OPTIONS:MAPCDUMB_DRV}
CONFIGURE_ARGS+=	--enable-dumb
.else
CONFIGURE_ARGS+=	--disable-dumb
.endif

.if ${PORT_OPTIONS:MCLIENT_ONLY}
CONFIGURE_ARGS+=	--enable-net \
			--disable-apcsmart --disable-dumb --disable-usb \
			--disable-snmp --disable-test --disable-pcnet
.endif

.if ${PORT_OPTIONS:MCGI}
CONFIGURE_ARGS+=	--enable-cgi --with-cgi-bin=${ETCDIR}/cgi
LIB_DEPENDS+=		gd:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CGI=""
.else
PLIST_SUB+=		CGI="@comment "
.endif

.if ${PORT_OPTIONS:MGAPCMON}
CONFIGURE_ARGS+=	--enable-gapcmon
USE_GNOME+=		gconf2
PLIST_SUB+=		GAPCMON=""
CONFLICTS+=		gapcmon-[0-9]*
.else
PLIST_SUB+=		GAPCMON="@comment "
.endif

.if ${PORT_OPTIONS:MPCNET_DRV}
CONFIGURE_ARGS+=	--enable-pcnet
.else
CONFIGURE_ARGS+=	--disable-pcnet
.endif

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=	--enable-usb
.endif

.if ${PORT_OPTIONS:MSNMP_DRV}
CONFIGURE_ARGS+=	--enable-snmp
.else
CONFIGURE_ARGS+=	--disable-snmp
.endif

.if ${PORT_OPTIONS:MSNMP_DRV_OLD}
LIB_DEPENDS+=		netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-net-snmp
.else
CONFIGURE_ARGS+=	--disable-net-snmp
.endif

.if ${PORT_OPTIONS:MTCP_WRAPPERS}
CONFIGURE_ARGS+=	--with-libwrap=yes
.endif

.if ${PORT_OPTIONS:MTEST_DRV}
CONFIGURE_ARGS+=	--enable-test
.endif

#CONFIGURE_ARGS+=	--with-libwrap=yes
#CONFIGURE_ENV+=		LIBS="-lcurses -lmenu"
#PLIST_SUB+=		POWERFL=""

pre-configure:
.if ${PORT_OPTIONS:MCLIENT_ONLY} && ( ${PORT_OPTIONS:MAPCSMART_DRV} || \
	${PORT_OPTIONS:MAPCDUMB_DRV} || ${PORT_OPTIONS:MPCNET_DRV} || \
	${PORT_OPTIONS:MPOWERFLUTE} || ${PORT_OPTIONS:MUSB} || \
	${PORT_OPTIONS:MSNMP_DRV} || ${PORT_OPTIONS:MTEST_DRV} )
	@${ECHO_CMD} "It doesn't make sense to build drivers if all you want is"
	@${ECHO_CMD} "the client; please do make config and select either"
	@${ECHO_CMD} "CLIENT_ONLY or the *_DRV you need"
	@${FALSE}
.endif

post-install:
#	If the files presaved are identical with the new one, include them in
#	the package list, so the port can be removed without problems
	for na in apccontrol commfailure mainsback mastertimeout \
		  changeme commok masterconnect onbattery; do \
		if [ -f ${ETCDIR}/$$na.orig ]; then \
			if cmp -s ${ETCDIR}/$$na ${ETCDIR}/$$na.orig; then \
				${ECHO_CMD} "%%ETCDIR%%/$$na.orig" >> ${TMPPLIST}; \
			fi \
		fi; \
	done
	@${ECHO_CMD} "@unexec if [ -d %D/${ETCDIR_REL} ]; then ${ECHO_CMD} \"If you are permanently removing this port, you should do a ``rm -rf ${ETCDIR}`` to remove config files left.\" | ${FMT} ; fi" >> ${TMPPLIST}
#	Install sample startup script
#	If there is already a config file it is installed as ...new
	for na in apcupsd.conf apcupsd.css hosts.conf multimon.conf; do \
		if [ -f ${ETCDIR}/$$na ]; then \
			if [ -f ${ETCDIR}/$$na.new ]; then \
				${MV} ${ETCDIR}/$$na.new ${ETCDIR}/$$na.sample; \
			else \
				${CP} ${ETCDIR}/$$na ${ETCDIR}/$$na.sample; \
			fi; \
		fi; \
	done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
