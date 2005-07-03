# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.10.17a
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de
COMMENT=	A daemon for controlling APC UPS

USE_GETTEXT=	yes
USE_REINPLACE=	yes

STARTUP_SCRIPT=	apcupsd.sh.sample
PLIST_SUB=	STARTUP_SCRIPT=${STARTUP_SCRIPT}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sbindir=${PREFIX}/sbin \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${PREFIX}/etc/apcupsd \
		--with-serial-dev=/dev/usv

OPTIONS=	CLIENT_ONLY "Build apcupsd client only (no network server)" off
OPTIONS+=	CGI "Compile with CGI programms to show status" off
OPTIONS+=	USB "Compile with USB Support (READ MANUAL!!!)" off
OPTIONS+=	SNMP "Compile with SNMP Support (READ MANUAL!!!)" off

.include <bsd.port.pre.mk>

.if defined(WITH_USB)
CONFIGURE_ARGS+=--enable-usb
.endif

.if defined(WITH_CGI)
CONFIGURE_ARGS+=--enable-cgi --with-cgi-bin=${PREFIX}/etc/apcupsd/cgi
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	CGI=""
.else
PLIST_SUB+=	CGI="@comment "
.endif

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=--enable-net
.else
CONFIGURE_ARGS+=--enable-master-slave
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"   \
		LDFLAGS="-L${LOCALBASE}/lib"

# Cause FreeBSD 3.X misses libmenu, libforms and libpanel (curses)
.if ${OSVERSION} > 400000
CONFIGURE_ARGS+=--enable-powerflute --with-libwrap=yes
PLIST_SUB+=	POWERFL=""
.else
PLIST_SUB+=	POWERFL="@comment "
.endif

MAN8=		"apcupsd.8"

PORTDOCS=	manual.pdf

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CGI=yes		if you want to build CGI support."
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want a network client."
	@${ECHO_MSG} "  WITH_USB=yes		to compile with USB support (READ MANUAL!!!)"
	@${ECHO_MSG} "  WITH_SNMP=yes		to compile with SNMP support (READ MANUAL!!!)"
	@${ECHO_MSG} ""
.if defined(WITH_CGI)
	@${ECHO_MSG} "===> Building with CGI support."
.endif
.if defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "===> Building network client."
.endif

post-configure:
	${REINPLACE_CMD} -e "s|%PREFIX%|${PREFIX}|g" ${WRKSRC}/doc/apcupsd.man

post-install:
# 	If the files presaved are identical with the new one, include then in
# 	the package list. So the port could be removed without problems
	for na in apccontrol commfailure mainsback mastertimeout \
		  changeme commok masterconnect onbattery; do \
		if [ -f ${PREFIX}/etc/apcupsd/$$na.orig ]; then \
			if cmp -s ${PREFIX}/etc/apcupsd/$$na ${PREFIX}/etc/apcupsd/$$na.orig; then \
				${ECHO_CMD} "etc/apcupsd/$$na.orig" >> ${TMPPLIST}; \
			fi \
		fi; \
	done
	${ECHO_CMD} "@unexec if [ -d %D/etc/apcupsd ]; then ${ECHO_CMD} \"If you are permanently removing this port, you should do a ``rm -rf ${PREFIX}/etc/apcupsd`` to remove config files left.\" | ${FMT} ; fi" >> ${TMPPLIST}
# 	Install sample startup script
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}
	${INSTALL_DATA} ${FILESDIR}/apcupsd.conf.net-master.sample ${PREFIX}/etc/apcupsd/
	${INSTALL_DATA} ${FILESDIR}/apcupsd.conf.net-slave.sample ${PREFIX}/etc/apcupsd/
# 	If there is already a config file it is installed as ...new
	for na in apcupsd.conf apcupsd.css hosts.conf multimon.conf; do \
		if [ -f ${PREFIX}/etc/apcupsd/$$na ]; then \
			if [ -f ${PREFIX}/etc/apcupsd/$$na.new ]; then \
				${MV} ${PREFIX}/etc/apcupsd/$$na.new ${PREFIX}/etc/apcupsd/$$na.sample; \
			else \
				${CP} ${PREFIX}/etc/apcupsd/$$na ${PREFIX}/etc/apcupsd/$$na.sample; \
			fi; \
		fi; \
	done

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for filen in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/texi/${filen} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
