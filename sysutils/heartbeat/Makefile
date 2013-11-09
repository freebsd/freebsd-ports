# Created by: Scott Kleihege <scott-ports@tummy.com>
# $FreeBSD$

PORTNAME=	heartbeat
PORTVERSION=	2.1.4
PORTREVISION=	20
CATEGORIES=	sysutils
#MASTER_SITES=	http://hg.linux-ha.org/lha-2.1/archive/STABLE-2.1.4.tar.bz2
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama/heartbeat
DISTNAME=	STABLE-${PORTVERSION}
DIST_SUBDIR=	heartbeat

MAINTAINER=	ports@encarnate.com
COMMENT=	Subsystem for High-Availability Clustering

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libnet.so:${PORTSDIR}/net/libnet \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libxml2.so:${PORTSDIR}/textproc/libxml2
PATCH_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtool libltdl
AUTOMAKE_ARGS+=	--add-missing --include-deps --copy
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes

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
SUB_LIST=	BATCH=${BATCH}

PKGDEINSTALL=	${PKGINSTALL}


MAN1=		cl_status.1 ha_logger.1 hb_addnode.1 hb_delnode.1 hb_standby.1 hb_takeover.1
MAN8=		apphbd.8 cibadmin.8 crm_resource.8 ha_logd.8 heartbeat.8 \
		meatclient.8 stonith.8

OPTIONS_DEFINE=MGMT LDIRECTORD APCSNMP DRAC3
MGMT_DESC=		Enable X11 Management Utilities
LDIRECTORD_DESC=	Enable Linux Director Daemon
APCSNMP_DESC=		Enable APC SNMP Stonith Device
DRAC3_DESC=		Enable Dell DRACIII Stonith Device

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !defined(BATCH)
BATCH=NO
.endif

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
MAN8+=			ldirectord.8
.else
CONFIGURE_ARGS+=	--disable-ldirectord
PLIST_SUB+=		LDIRECTORD="@comment "
.endif

.if ${PORT_OPTIONS:MAPCSNMP} || exists (${PREFIX}/lib/libnetsnmp.so)
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
PLIST_SUB+=	APCSNMP=""
.else
PLIST_SUB+=	APCSNMP="@comment "
.endif

.if ${PORT_OPTIONS:MDRAC3} || exists (${PREFIX}/lib/libcurl.so)
USE_CURL=	yes
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	DRAC3=""
.else
PLIST_SUB+=	DRAC3="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

# BladeHPI Stonith Automagic Building
.if exists (${PREFIX}/include/openhpi/SaHpi.h)
PLIST_SUB+=	HPI=""
.else
PLIST_SUB+=	HPI="@comment "
.endif

# IPMI Lan Stonight Automagic Building
.if exists (${PREFIX}/include/ipmilan.h)
PLIST_SUB+=	IPMI=""
.else
PLIST_SUB+=	IPMI="@comment "
.endif

# VACM Stonith Automagic Building
.if exists (${PREFIX}/include/vacmclient_api.h)
PLIST_SUB+=	VACM=""
.else
PLIST_SUB+=	VACM="@comment "
.endif

pre-patch:
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
.if ${PORT_OPTIONS:MDOCS}
	# Install sample configuration
	@if [ ! -f ${PREFIX}/etc/ha.d/authkeys ]; then \
		${CP} -p ${DOCSDIR}/authkeys ${PREFIX}/etc/ha.d/authkeys ; \
	fi
	${CP} -p ${DOCSDIR}/authkeys ${PREFIX}/etc/ha.d/authkeys.sample
	${CHMOD} 600 ${PREFIX}/etc/ha.d/authkeys*

	@if [ ! -f ${PREFIX}/etc/ha.d/ha.cf ]; then \
		${CP} -p ${DOCSDIR}/ha.cf ${PREFIX}/etc/ha.d/ha.cf ; \
	fi
	${CP} -p ${DOCSDIR}/ha.cf ${PREFIX}/etc/ha.d/ha.cf.sample

	@if [ ! -f ${PREFIX}/etc/ha.d/logd.cf ]; then \
		${CP} -p ${DOCSDIR}/logd.cf ${PREFIX}/etc/ha.d/logd.cf ; \
	fi
	${CP} -p ${DOCSDIR}/logd.cf ${PREFIX}/etc/ha.d/logd.cf.sample
.endif

.if ${PORT_OPTIONS:MLDIRECTORD}
	@if [ ! -f ${PREFIX}/etc/ha.d/ldirectord.cf ]; then \
		${CP} -p ${WRKSRC}/ldirectord/ldirectord.cf ${PREFIX}/etc/ha.d/ldirectord.cf ; \
		${CP} -p ${WRKSRC}/ldirectord/ldirectord.cf ${PREFIX}/etc/ha.d/ldirectord.cf.sample ; \
	fi
.endif

	# Some subdirs treat man as documentation, therefor we have to install
	# those man pages manually if NOPORTDOCS is defined.

.if ${PORT_OPTIONS:MDOCS}
	# Some subdirs treat man as documentation, therefor we have to install
	# those man pages manually if NOPORTDOCS is defined.

.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man1
.endfor
.for f in apphbd.8 cibadmin.8 crm_resource.8 ha_logd.8 heartbeat.8
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man8
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
