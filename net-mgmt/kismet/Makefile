# Created by: Thomas Spreng <spreng@socket.ch>
# $FreeBSD$

PORTNAME=	kismet
DISTVERSION=	2013-03-R1b
PORTREVISION=	1
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
USES=		gmake tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		PCRE PLUGINS SETUID DOCS EXAMPLES
OPTIONS_DEFAULT=	PCRE PLUGINS SETUID
SETUID_DESC=		Use privilege separation

WRKSRC=	${WRKDIR}/${DISTNAME:S/a$$//}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README manuf
DISTFILES+=	manuf:2
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=--enable-pcre
LIB_DEPENDS+=	libpcre.so:devel/pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif

.if ${PORT_OPTIONS:MSETUID}
GROUPS=		kismet
CONFIGURE_ARGS+=--with-suidgroup=wheel
INSTALL_TARGET=		suidinstall
PLIST_SUB+=	SUID="" SUIDGROUP="${GROUPS}"
PKGMESSAGE=	${WRKDIR}/suid_pkg-message
SUB_FILES+=	suid_pkg-message
.else
INSTALL_TARGET=		install
CONFIGURE_ARGS+=--without-suidgroup
PLIST_SUB+=	SUID="@comment " SUIDGROUP=""
.endif

.if ${PORT_OPTIONS:MPLUGINS}
ALL_TARGET=	depend all all-plugins
INSTALL_TARGET+=	all-plugins-install
USE_OPENSSL=	yes
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
		-e "s/make/${MAKE_CMD}/" \
		-e "s/\$$(MAKE)/${MAKE_CMD}/" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s/CXXFLAGS/CPPFLAGS/" \
		${WRKSRC}/plugin-alertsyslog/Makefile
	@${FIND} ${WRKSRC} -type f -name 'Makefile' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -E \
		'/C(XX)?FLAGS[[:blank:]]*\+=/s/ -g / /'
	@${FIND} ${WRKSRC} -type f \( -name Makefile -o -name Makefile.in \) -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,-o $$(INSTUSR) -g $$(INSTGRP),,' \
		-e 's,-o $$(INSTUSR) -g $$(MANGRP),,' \
		-e 's,-o $$(INSTUSR) -g $$(SUIDGROUP) -m 4550,,'

post-build:
	@cd ${WRKSRC}; ${STRIP_CMD} kismet_client kismet_drone kismet_server */*.so

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manuf ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ruby/* ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${MV} ${STAGEDIR}${PREFIX}/etc/kismet.conf \
		${STAGEDIR}${PREFIX}/etc/kismet.conf.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/kismet_drone.conf \
		${STAGEDIR}${PREFIX}/etc/kismet_drone.conf.sample

.include <bsd.port.mk>
