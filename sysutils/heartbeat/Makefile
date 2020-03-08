# Created by: Scott Kleihege <scott-ports@tummy.com>
# $FreeBSD$

PORTNAME=	heartbeat
PORTVERSION=	2.1.4
PORTREVISION=	29
CATEGORIES=	sysutils
#MASTER_SITES=	http://hg.linux-ha.org/lha-2.1/archive/STABLE-2.1.4.tar.bz2
MASTER_SITES=	LOCAL/kuriyama/heartbeat
DISTNAME=	STABLE-${PORTVERSION}
DIST_SUBDIR=	heartbeat

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Subsystem for High-Availability Clustering

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libgnutls.so:security/gnutls \
		libnet.so:net/libnet \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxml2.so:textproc/libxml2
BUILD_DEPENDS=	bison:devel/bison

USES=		autoreconf cpe gettext gmake gnome libtool perl5 pkgconfig \
		python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	ldirectord/ldirectord.in \
		lib/plugins/stonith/external/ibmrsa-telnet \
		lib/plugins/stonith/external/vmware \
		lib/plugins/stonith/external/xen0-ha-dom0-stonith-helper \
		lib/plugins/stonith/external/xen0-ha.in
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CPE_VENDOR=	linux-ha

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USERS=		hacluster
GROUPS=		haclient

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-miBsdir=${PREFIX}/snmp/mibs \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-group-id=275 \
		--with-ccmuser-id=275 \
		--with-ocf-root=${PREFIX}/etc/ocf \
		--disable-rpath \
		--disable-dopd \
		--disable-fatal-warnings

SUB_FILES=	pkg-message

PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}

OPTIONS_DEFINE=		MGMT LDIRECTORD APCSNMP DRAC3 DOCS
MGMT_DESC=		Enable X11 Management Utilities
LDIRECTORD_DESC=	Enable Linux Director Daemon
APCSNMP_DESC=		Enable APC SNMP Stonith Device
DRAC3_DESC=		Enable Dell DRACIII Stonith Device

APCSNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
DRAC3_LIB_DEPENDS=	libcurl.so:ftp/curl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMGMT}
BUILD_DEPENDS+=		swig3.0:devel/swig30
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:x11-toolkits/py-gtk2
BINARY_ALIAS=		swig=swig3.0
PLIST_SUB+=		MGMT=""
.else
CONFIGURE_ARGS+=	--disable-mgmt
PLIST_SUB+=		MGMT="@comment "
.endif

.if ${PORT_OPTIONS:MLDIRECTORD}
RUN_DEPENDS+=		p5-libwww>=0:www/p5-libwww \
			p5-Mail-Tools>=0:mail/p5-Mail-Tools
USES+=			perl5
USE_PERL5=		run
PLIST_SUB+=		LDIRECTORD=""
.else
CONFIGURE_ARGS+=	--disable-ldirectord
PLIST_SUB+=		LDIRECTORD="@comment "
.endif

.if ${PORT_OPTIONS:MAPCSNMP}
PLIST_SUB+=	APCSNMP=""
.else
PLIST_SUB+=	APCSNMP="@comment "
.endif

.if ${PORT_OPTIONS:MDRAC3}
PLIST_SUB+=	DRAC3=""
.else
PLIST_SUB+=	DRAC3="@comment "
.endif

# BladeHPI Stonith Automagic Building
.if exists (${STAGEDIR}${PREFIX}/include/openhpi/SaHpi.h)
PLIST_SUB+=	HPI=""
.else
PLIST_SUB+=	HPI="@comment "
.endif

# IPMI Lan Stonith Automagic Building
.if exists (${STAGEDIR}${PREFIX}/include/ipmilan.h)
PLIST_SUB+=	IPMI=""
.else
PLIST_SUB+=	IPMI="@comment "
.endif

# VACM Stonith Automagic Building
.if exists (${STAGEDIR}${PREFIX}/include/vacmclient_api.h)
PLIST_SUB+=	VACM=""
.else
PLIST_SUB+=	VACM="@comment "
.endif

post-extract:
	@${MV} ${WRKDIR}/Heartbeat-STABLE-2-1-${DISTNAME} ${WRKSRC}
	@${CP} -f ${FILESDIR}/heartbeat.in ${WRKSRC}/heartbeat/init.d/

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/resources/OCF/IPaddr
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|^\(docdir.*doc/\).*|\1${PORTNAME}|' \
		${WRKSRC}/configure.in \
		${WRKSRC}/doc/Makefile.am
.else
	@${REINPLACE_CMD} -e 's| doc | |' \
		${WRKSRC}/Makefile.am
.endif

post-install:
	${MKDIR} -m 0750 ${STAGEDIR}/var/run/heartbeat/pengine
	${MKDIR} ${STAGEDIR}/var/lib/heartbeat/mgmt

.if ${PORT_OPTIONS:MDOCS}
	# Install sample configuration
	${CP} -p ${STAGEDIR}${DOCSDIR}/authkeys ${STAGEDIR}${PREFIX}/etc/ha.d/authkeys.sample
	${CP} -p ${STAGEDIR}${DOCSDIR}/ha.cf ${STAGEDIR}${PREFIX}/etc/ha.d/ha.cf.sample
	${CP} -p ${STAGEDIR}${DOCSDIR}/logd.cf ${STAGEDIR}${PREFIX}/etc/ha.d/logd.cf.sample
.endif

.if ${PORT_OPTIONS:MLDIRECTORD}
	${CP} -p ${WRKSRC}/ldirectord/ldirectord.cf ${STAGEDIR}${PREFIX}/etc/ha.d/ldirectord.cf.sample
.endif

.include <bsd.port.mk>
