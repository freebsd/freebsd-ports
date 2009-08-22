# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.14.5
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

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"   \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN8=		apcupsd.8

OPTIONS=	APCSMART_DRV "Compile APC SmartUPS serial driver" on \
		APCDUMB_DRV "Compile dumb UPS driver" on \
		CLIENT_ONLY "Only NIS client (no network server or drivers)" off \
		CGI "Compile with CGI programms to show status" off \
		PCNET_DRV "Compile PowerChute Network Shutdown driver" on \
		USB "Compile with USB Support driver" on \
		SNMP_DRV "Compile with SNMP driver" on \
		TCP_WRAPPERS "Compile with TCP_WRAPPERS support" on\
		TEST_DRV "Compile TEST driver" off \
		GAPCMON "Build GTK GUI front-end" off
#               POWERFLUTE "Compile powerflute program" off

PORTDOCS=	${PORTNAME}.pdf

.include <bsd.port.options.mk>

.ifdef(WITH_APCSMART_DRV)
CONFIGURE_ARGS+=	--enable-apcsmart
.else
CONFIGURE_ARGS+=	--disable-apcsmart
.endif

.ifdef(WITH_APCDUMB_DRV)
CONFIGURE_ARGS+=	--enable-dumb
.else
CONFIGURE_ARGS+=	--disable-dumb
.endif

.ifdef(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--enable-net \
			--disable-apcsmart --disable-dumb --disable-usb \
			--disable-snmp --disable-test --disable-pcnet
.endif

.ifdef(WITH_CGI)
CONFIGURE_ARGS+=	--enable-cgi --with-cgi-bin=${ETCDIR}/cgi
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CGI=""
.else
PLIST_SUB+=		CGI="@comment "
.endif

.ifdef(WITH_GAPCMON)
CONFIGURE_ARGS+=	--enable-gapcmon
USE_GNOME+=		gconf2
PLIST_SUB+=		GAPCMON=""
CONFLICTS+=		gapcmon-[0-9]*
.else
PLIST_SUB+=		GAPCMON="@comment "
.endif

.ifdef(WITH_PCNET_DRV)
CONFIGURE_ARGS+=	--enable-pcnet
.else
CONFIGURE_ARGS+=	--disable-pcnet
.endif

# disabled upstream
.ifdef(WITH_POWERFLUTE)
CONFIGURE_ARGS+=	--enable-powerflute
CONFIGURE_ENV+=		LIBS+="-lcurses -lmenu"
PLIST_SUB+=		POWERFL=""
.else
PLIST_SUB+=		POWERFL="@comment "
.endif

.ifdef(WITH_USB)
CONFIGURE_ARGS+=	--enable-usb
.endif

.ifdef(WITH_SNMP_DRV)
LIB_DEPENDS+=		netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-snmp
.else
CONFIGURE_ARGS+=	--disable-snmp
.endif

.ifdef(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--with-libwrap=yes
.endif

.ifdef(WITH_TEST_DRV)
CONFIGURE_ARGS+=	--enable-test
.endif

#CONFIGURE_ARGS+=	--with-libwrap=yes
#CONFIGURE_ENV+=		LIBS="-lcurses -lmenu"
#PLIST_SUB+=		POWERFL=""

.include <bsd.port.pre.mk>

.if defined(WITH_USB) && ${OSVERSION} >= 800069
CONFIGURE_ARGS+=	--with-generic-usb
.endif

pre-configure:
.if defined(WITH_CLIENT_ONLY) && ( defined(WITH_APCSMART_DRV) || \
	defined(WITH_APCDUMB_DRV) || defined(WITH_PCNET_DRV) || \
	defined(WITH_POWERFLUTE) || defined(WITH_USB) || \
	definedWITH_SNMP_DRV) || defined(WITH_TEST_DRV) )
	@${ECHO_CMD} "It doesn't make sense to build drivers if all you want is"
	@${ECHO_CMD} "the client; please do make config and select either"
	@${ECHO_CMD} "CLIENT_ONLY or the *_DRV you need"
	@${FALSE}
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|%PREFIX%|${PREFIX}|g" ${WRKSRC}/doc/apcupsd.man

post-install:
#	If the files presaved are identical with the new one, include then in
#	the package list. So the port could be removed without problems
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
