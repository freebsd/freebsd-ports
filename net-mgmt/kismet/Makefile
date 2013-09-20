# Created by: Thomas Spreng <spreng@socket.ch>
# $FreeBSD$

PORTNAME=	kismet
DISTVERSION=	2013-03-R1b
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/:1 \
		http://anonsvn.wireshark.org/wireshark/trunk/:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XZ=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		kismet.1 kismet_drone.1
MAN5=		kismet.conf.5 kismet_drone.conf.5

OPTIONS_DEFINE=		PCRE PLUGINS SETUID
OPTIONS_DEFAULT=	PCRE PLUGINS SETUID
SETUID_DESC=		Use privilege separation

WRKSRC=	${WRKDIR}/${DISTNAME:S/a$$//}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README manuf
DISTFILES+=	manuf:2
IGNOREFILES=	manuf
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=--enable-pcre
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif

.if ${PORT_OPTIONS:MSETUID}
GROUPS =	kismet
CONFIGURE_ARGS+=--with-suidgroup=${GROUPS}
INSTALL_TARGET =	suidinstall
PLIST_SUB+=	SUID=""
PKGMESSAGE=	${WRKDIR}/suid_pkg-message
SUB_FILES+=	suid_pkg-message
.else
INSTALL_TARGET =	install
CONFIGURE_ARGS+=--without-suidgroup
PLIST_SUB+=	SUID="@comment "
.endif

.if ${PORT_OPTIONS:MPLUGINS}
ALL_TARGET=	depend all all-plugins
INSTALL_TARGET+=	all-plugins-install
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
	@${REINPLACE_CMD} -e "s/CXXFLAGS/CPPFLAGS/" \
		${WRKSRC}/plugin-alertsyslog/Makefile
	@${FIND} ${WRKSRC} -type f -name 'Makefile' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -E \
		'/C(XX)?FLAGS[[:blank:]]*\+=/s/ -g / /'

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manuf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ruby/* ${EXAMPLESDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf \
		${PREFIX}/etc/kismet.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf \
		${PREFIX}/etc/kismet_drone.conf.sample

.include <bsd.port.mk>
