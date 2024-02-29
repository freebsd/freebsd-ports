PORTNAME=	kismet
DISTVERSION=	2016-07-R1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS
WWW=		https://www.kismetwireless.net/

LICENSE=	GPLv2

USES=		gmake localbase:ldflags tar:xz
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

WRKSRC=	${WRKDIR}/${DISTNAME:S/a$$//}

PORTDOCS=	README
PORTEXAMPLES=	*

OPTIONS_DEFINE=		PCRE PLUGINS SETUID DOCS EXAMPLES
OPTIONS_DEFAULT=	PCRE PLUGINS SETUID
OPTIONS_SUB=		yes

SETUID_DESC=		Use privilege separation

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre
PLUGINS_USES=	ssl
PLUGINS_ALL_TARGET=	depend all all-plugins
PLUGINS_INSTALL_TARGET=	all-plugins-install
SETUID_CONFIGURE_ON=--with-suidgroup=wheel
SETUID_CONFIGURE_OFF=--without-suidgroup
SETUID_INSTALL_TARGET=		suidinstall
SETUID_INSTALL_TARGET_OFF=		install
SETUID_SUB_FILES=	suid_pkg-message
SETUID_PLIST_SUB=	SUID="" SUIDGROUP="${GROUPS}"
SETUID_PLIST_SUB_OFF=	SUID="@comment " SUIDGROUP=""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSETUID}
GROUPS=		kismet
PKGMESSAGE=	${WRKDIR}/suid_pkg-message
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-restricted-plugin-ptw_aircrack-crypto.cc
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
	cd ${WRKSRC}; ${STRIP_CMD} kismet_client kismet_drone kismet_server */*.so

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ruby/* ${STAGEDIR}${EXAMPLESDIR}
.endif
	${MV} ${STAGEDIR}${PREFIX}/etc/kismet.conf \
		${STAGEDIR}${PREFIX}/etc/kismet.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/kismet_drone.conf \
		${STAGEDIR}${PREFIX}/etc/kismet_drone.conf.sample

.include <bsd.port.post.mk>
