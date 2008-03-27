# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.14.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:src_sf/g} \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/:src_bk \
		http://apcupsd.sourceforge.net/manual/:doc_sf \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/:doc_bk
MASTER_SITE_SUBDIR=	${PORTNAME}/:src_sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src_sf,src_bk \
		${PORTNAME}.pdf:doc_sf,doc_bk
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
IGNOREFILES=	${PORTNAME}.pdf

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A daemon for controlling APC UPS

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_RC_SUBR=	apcupsd
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/sbin \
		--with-nologin=/var/run \
		--disable-install-distdir \
		--sysconfdir=${ETCDIR} \
		--with-serial-dev=/dev/usv

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"   \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN8=		apcupsd.8

OPTIONS=	CLIENT_ONLY "Build NIS client only (no network server)" off \
		CGI "Compile with CGI programms to show status" off \
		USB "Compile with USB Support (READ MANUAL!)" on \
		SNMP "Compile with SNMP Support (READ MANUAL!)" on

PORTDOCS=	${PORTNAME}.pdf

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--enable-net
.endif

.if defined(WITH_CGI)
CONFIGURE_ARGS+=	--enable-cgi --with-cgi-bin=${ETCDIR}/cgi
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CGI=""
.else
PLIST_SUB+=		CGI="@comment "
.endif

.if !defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--enable-usb
.endif

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS+=		netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
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
	cd ${DISTDIR} && ${INSTALL_DATA} ${PORTNAME}.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
