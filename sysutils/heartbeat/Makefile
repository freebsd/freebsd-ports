# Created by: Scott Kleihege <scott-ports@tummy.com>
# $FreeBSD$

PORTNAME=	heartbeat
PORTVERSION=	2.1.4
PORTREVISION=	22
CATEGORIES=	sysutils
#MASTER_SITES=	http://hg.linux-ha.org/lha-2.1/archive/STABLE-2.1.4.tar.bz2
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama/heartbeat
DISTNAME=	STABLE-${PORTVERSION}
DIST_SUBDIR=	heartbeat

MAINTAINER=	ports@encarnate.com
COMMENT=	Subsystem for High-Availability Clustering

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libnet.so:${PORTSDIR}/net/libnet \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libxml2.so:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
PATCH_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

USE_AUTOTOOLS=	autoconf autoheader automake aclocal libltdl libtoolize
AUTOMAKE_ARGS+=	--add-missing --include-deps --copy
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal

USES=		gettext gmake libtool pkgconfig tar:bzip2 shebangfix
SHEBANG_FILES=	ldirectord/ldirectord.in
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes

USERS=		hacluster
GROUPS=		haclient

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libnet11
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/libnet11

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--localstatedir=/var \
		--with-miBsdir=${PREFIX}/snmp/mibs \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-group-id=275 \
		--with-ccmuser-id=275 \
		--with-ocf-root=${PREFIX}/etc/ocf \
		--disable-rpath \
		--disable-dopd \
		--disable-fatal-warnings

SUB_FILES=	pkg-install pkg-message

PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}

OPTIONS_DEFINE=		MGMT LDIRECTORD APCSNMP DRAC3
MGMT_DESC=		Enable X11 Management Utilities
LDIRECTORD_DESC=	Enable Linux Director Daemon
APCSNMP_DESC=		Enable APC SNMP Stonith Device
DRAC3_DESC=		Enable Dell DRACIII Stonith Device

APCSNMP_LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
DRAC3_LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMGMT}
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=		MGMT=""
.else
CONFIGURE_ARGS+=	--disable-mgmt
PLIST_SUB+=		MGMT="@comment "
.endif

.if ${PORT_OPTIONS:MLDIRECTORD}
RUN_DEPENDS+=		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
			p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
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
	@${LN} -s ${WRKSRC}/include/config.h ${WRKSRC}/config.h

	@${LN} -s $AUTOCONF ${WRKSRC}/autoconf
	@${LN} -s $AUTOHEADER ${WRKSRC}/autoheader
	@${LN} -s $AUTOMAKE ${WRKSRC}/automake
	@${LN} -s $LIBTOOL ${WRKSRC}/libtool

	@cd ${WRKSRC} && \
	${LIBTOOLIZE} --automake --ltdl --force --copy && \
	${TAR} -cf libltdl.tar libltdl && \
	${RM} -rf libltdl

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|^\(docdir.*doc/\).*|\1${PORTNAME}|' \
		${WRKSRC}/configure.in \
		${WRKSRC}/doc/Makefile.am
.else
	@${REINPLACE_CMD} -e 's| doc | |' \
		${WRKSRC}/Makefile.am
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/heartbeat/plugins/*/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pils/plugins/InterfaceMgr/generic.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/stonith/plugins/stonith2/*.so
	${MKDIR} -m 0750 ${STAGEDIR}/var/run/heartbeat/pengine
	${TOUCH} ${STAGEDIR}/var/run/heartbeat.pid

.if ${PORT_OPTIONS:MMGMT}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/heartbeat-gui/_pymgmt.so.0.0.0
.endif

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
