# New ports collection makefile for:	heartbeat
# Date created:				18 March 2005
# Whom:					Scott Kleihege <scott-ports@tummy.com>
#
# $FreeBSD$
#

PORTNAME=	heartbeat
PORTVERSION=	2.1.4
PORTREVISION=	3
CATEGORIES=	sysutils
#MASTER_SITES=	http://hg.linux-ha.org/lha-2.1/archive/STABLE-2.1.4.tar.bz2
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama/heartbeat
DISTNAME=	STABLE-${PORTVERSION}
DIST_SUBDIR=	heartbeat

MAINTAINER=	ports@encarnate.com
COMMENT=	Subsystem for High-Availability Clustering

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		net-1.1.3:${PORTSDIR}/net/libnet-devel \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		xml2:${PORTSDIR}/textproc/libxml2
PATCH_DEPENDS=	${LOCALBASE}/bin/libtoolize:${PORTSDIR}/devel/libtool22

USE_AUTOTOOLS=	autoconf:262 autoheader:262 automake:110 aclocal:110 \
		libtool:22 libltdl:22
AUTOMAKE_ARGS+=	--add-missing --include-deps --copy
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/libnet113" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${LOCALBASE}/lib/libnet113"

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

OPTIONS=	MGMT "Enable X11 Management Utilities" Off \
		LDIRECTORD "Enable Linux Director Daemon" Off

.include <bsd.port.pre.mk>

.if !defined(BATCH)
BATCH=NO
.endif

.if defined(WITH_MGMT)
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=		MGMT=""
.else
CONFIGURE_ARGS+=	--disable-mgmt
PLIST_SUB+=		MGMT="@comment "
.endif

.if defined(WITH_LDIRECTORD)
RUN_DEPENDS+=		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
			${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools
#ipvsadm:${PORTSDIR}/net/ipvs
USE_PERL5_RUN=		yes
PLIST_SUB+=		LDIRECTORD=""
MAN8+=			ldirectord.8
.else
CONFIGURE_ARGS+=	--disable-ldirectord
PLIST_SUB+=		LDIRECTORD="@comment "
.endif

pre-patch:
	@${MV} ${WRKDIR}/Heartbeat-STABLE-2-1-${DISTNAME} ${WRKSRC}

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

.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^\(docdir.*doc/\).*|\1${PORTNAME}|' \
		${WRKSRC}/configure.in \
		${WRKSRC}/doc/Makefile.am
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
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

.if defined(WITH_LDIRECTORD)
	@if [ ! -f ${PREFIX}/etc/ha.d/ldirectord.cf ]; then \
		${CP} -p ${WRKSRC}/ldirectord/ldirectord.cf ${PREFIX}/etc/ha.d/ldirectord.cf ; \
		${CP} -p ${WRKSRC}/ldirectord/ldirectord.cf ${PREFIX}/etc/ha.d/ldirectord.cf.sample ; \
	fi
.endif

	# Some subdirs treat man as documentation, therefor we have to install
	# those man pages manually if NOPORTDOCS is defined.

.if defined(NOPORTDOCS)
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man1
.endfor
.for f in apphbd.8 cibadmin.8 crm_resource.8 ha_logd.8 heartbeat.8
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man8
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${SH} ${PKGINSTALL} ${PKGNAME} DEINSTALL

.include <bsd.port.post.mk>
