# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.14.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:src_sf/g} \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/:src_bk \
		http://apcupsd.sourceforge.net/manual/:doc_sf \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/:doc_bk
MASTER_SITE_SUBDIR=	${PORTNAME}/:src_sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src_sf,src_bk \
		${PORTNAME}.pdf:doc_sf,doc_bk
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A daemon for controlling APC UPS

USE_GETTEXT=	yes
USE_RC_SUBR=	apcupsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sbindir=${PREFIX}/sbin \
		--mandir=${MANPREFIX}/man \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${PREFIX}/etc/apcupsd \
		--with-serial-dev=/dev/usv

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"   \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN8=		apcupsd.8

OPTIONS=	CLIENT_ONLY "Build NIS client only (no network server)" off \
		CGI "Compile with CGI programms to show status" off \
		USB "Compile with USB Support (READ MANUAL!)" on \
		SNMP "Compile with SNMP Support (READ MANUAL!)" on

IGNOREFILES=	${PORTNAME}.pdf
PORTDOCS=	${PORTNAME}.pdf

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--enable-net
.endif

.if defined(WITH_CGI)
CONFIGURE_ARGS+=	--enable-cgi --with-cgi-bin=${PREFIX}/etc/apcupsd/cgi
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CGI=""
.else
PLIST_SUB+=		CGI="@comment "
.endif

.if !defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--enable-usb
.endif

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS+=		netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-snmp
.endif

CONFIGURE_ARGS+=	--enable-powerflute --with-libwrap=yes
CONFIGURE_ENV+=		LIBS="-lcurses -lmenu"
PLIST_SUB+=		POWERFL=""

post-configure:
	@${REINPLACE_CMD} -e "s|%PREFIX%|${PREFIX}|g" ${WRKSRC}/doc/apcupsd.man

post-install:
#	If the files presaved are identical with the new one, include then in
#	the package list. So the port could be removed without problems
	for na in apccontrol commfailure mainsback mastertimeout \
		  changeme commok masterconnect onbattery; do \
		if [ -f ${PREFIX}/etc/apcupsd/$$na.orig ]; then \
			if cmp -s ${PREFIX}/etc/apcupsd/$$na ${PREFIX}/etc/apcupsd/$$na.orig; then \
				${ECHO_CMD} "etc/apcupsd/$$na.orig" >> ${TMPPLIST}; \
			fi \
		fi; \
	done
	@${ECHO_CMD} "@unexec if [ -d %D/etc/apcupsd ]; then ${ECHO_CMD} \"If you are permanently removing this port, you should do a ``rm -rf ${PREFIX}/etc/apcupsd`` to remove config files left.\" | ${FMT} ; fi" >> ${TMPPLIST}
#	Install sample startup script
#	If there is already a config file it is installed as ...new
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
	cd ${DISTDIR} && ${INSTALL_DATA} ${PORTNAME}.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
