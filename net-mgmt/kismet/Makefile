# New ports collection makefile for:	kismet
# Date created:			3 May 2004
# Whom:					Thomas Spreng <spreng@socket.ch>
#
# $FreeBSD$
#

PORTNAME=	kismet
DISTVERSION=	2011-01-R1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/:1 \
		http://anonsvn.wireshark.org/wireshark/trunk/:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

MAN1=		kismet.1 kismet_drone.1
MAN5=		kismet.conf.5 kismet_drone.conf.5

OPTIONS=	PCRE "Build kismet with PCRE regex filters" on \
		PLUGINS "Build and install plugins" off \
		SETUID "Build kismet with privilege separation" on

.include <bsd.port.options.mk>

.ifndef(NOPORTDOCS)
PORTDOCS=	README manuf
DISTFILES+=	manuf:2
IGNOREFILES=	manuf
.endif

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

.ifdef(WITH_PCRE)
CONFIGURE_ARGS+=--enable-pcre
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif

.ifdef(WITH_SETUID)
KISMET_GROUP?=	kismet
CONFIGURE_ARGS+=--with-suidgroup=${KISMET_GROUP}
INSTALL_TARGET =	suidinstall
PLIST_SUB+=	SUID=""
PKGINSTALL=	${PKGDIR}/suid_pkg-install
PKGDEINSTALL =	${PKGDIR}/suid_pkg-deinstall
PKGMESSAGE=	${WRKDIR}/suid_pkg-message
SUB_FILES+=	suid_pkg-message
SUB_LIST+=	KISMET_GROUP=${KISMET_GROUP}

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.else
INSTALL_TARGET =	install
CONFIGURE_ARGS+=--without-suidgroup
PLIST_SUB+=	SUID="@comment "
.endif

.ifdef(WITH_PLUGINS)
ALL_TARGET=	depend all-with-plugins
INSTALL_TARGET+=	plugins-install
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "/gps=/s/true/false/" \
		-e "/ouifile=/{/wireshark/d;s|/etc|${DOCSDIR}|;}" \
			${WRKSRC}/conf/kismet.conf.in \
			${WRKSRC}/conf/kismet_drone.conf
	@${REINPLACE_CMD} -e "s/plugin-/plugin-[aps]/" \
		-e "s/make/${GMAKE}/" \
		-e "s/\$$(MAKE)/${GMAKE}/" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/PLUGINLDFLAGS/d" \
		${WRKSRC}/Makefile.inc.in

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manuf ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ruby/* ${EXAMPLESDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf \
		${PREFIX}/etc/kismet.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf \
		${PREFIX}/etc/kismet_drone.conf.sample

.include <bsd.port.mk>
