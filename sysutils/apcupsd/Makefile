# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.10.11
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
		--disable-install-distdir --enable-usb \
		--sysconfdir=${PREFIX}/etc/apcupsd \
		--with-serial-dev=/dev/usv

# We need this below
CONF_FILES=apcupsd.conf

.if defined(WITH_CGI)
CONFIGURE_ARGS+=--enable-cgi --with-cgi-bin=${PREFIX}/etc/apcupsd/cgi
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	CGI=""
CONF_FILES+=	multimon.conf hosts.conf
.else
PLIST_SUB+=	CGI="@comment "
.endif

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=--enable-net
.else
CONFIGURE_ARGS+=--enable-master-slave
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"   \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

# Cause FreeBSD 3.X misses libmenu, libforms and libpanel (curses)
.if ${OSVERSION} > 400000
CONFIGURE_ARGS+=--enable-powerflute --with-libwrap=yes
PLIST_SUB+=	POWERFL=""
.else
PLIST_SUB+=	POWERFL="@comment "
.endif

MAN8=		"apcupsd.8"

PORTDOCS=	apcupsd.pdf manual.html manual.css \
		apcupsd.png back.png charging.png home.png main_configs.png \
		multimon.png next.png onbatt.png online.png status.png thanks.png \
		wininstall1.png wininstall2.png	wininstall3.png wininstall4.png \
		wininstall5.png wininstall6.png wininstall7.png

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CGI=yes		if you want to build CGI support."
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want a network client."
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
	# Check if the install presaves the configuration files
	for na in ${CONF_FILES}; do \
		if [ -f ${PREFIX}/etc/apcupsd/$$na.new ]; then \
			${ECHO_CMD} "etc/apcupsd/$$na.new" >> ${TMPPLIST}; \
			if cmp -s ${PREFIX}/etc/apcupsd/$$na.new ${PREFIX}/etc/apcupsd/$$na; then \
				${ECHO_CMD} "etc/apcupsd/$$na" >> ${TMPPLIST}; \
			fi \
		else \
			${ECHO_CMD} "etc/apcupsd/$$na" >> ${TMPPLIST}; \
		fi; \
	done
	# If the files presaved are identical with the new one, include then in
	# the package list. So the port could be removed without problems
	for na in apccontrol commfailure mainsback mastertimeout \
		  changeme commok masterconnect onbattery; do \
		if [ -f ${PREFIX}/etc/apcupsd/$$na.orig ]; then \
			if cmp -s ${PREFIX}/etc/apcupsd/$$na ${PREFIX}/etc/apcupsd/$$na.orig; then \
				${ECHO_CMD} "etc/apcupsd/$$na.orig" >> ${TMPPLIST}; \
			fi \
		fi; \
	done
	${ECHO_CMD} "@dirrm etc/apcupsd" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec if [ -d %D/etc/apcupsd ]; then echo \"If you are permanently removing this port, you should do a ``rm -rf ${PREFIX}/etc/apcupsd`` to remove config files left.\" | fmt ; fi" >> ${TMPPLIST}
	# Install sample startup script
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}
	${INSTALL_DATA} ${FILESDIR}/apcupsd.conf.net-master.sample ${PREFIX}/etc/apcupsd/
	${INSTALL_DATA} ${FILESDIR}/apcupsd.conf.net-slave.sample ${PREFIX}/etc/apcupsd/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for filen in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/docbook/${filen} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
