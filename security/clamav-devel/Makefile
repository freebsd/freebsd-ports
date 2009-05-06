# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20090506
CATEGORIES=	security
MASTER_SITES=	http://www.clamav.net/snapshot/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/clamav-devel
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Command line virus scanner written entirely in C

OPTIONS=	ARC "Enable arch archives support" On \
		ARJ "Enable arj archives support" On \
		LHA "Enable lha archives support" On \
		UNZOO "Enable zoo archives support" On \
		UNRAR "Enable rar archives support" On \
		MILTER "Compile the milter interface" Off \
		LDAP "libmilter was built with LDAP" Off \
		ICONV "Enable ICONV support" Off \
		STDERR "Print logs to stderr instead of stdout" Off

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
USE_RC_SUBR=	clamav-clamd clamav-freshclam
CONF_FILES=	clamd freshclam

PORTDOCS=	*

DBDIR=		/var/db/clamav
LOGDIR=		/var/log/clamav
RUNDIR=		/var/run/clamav
PLIST_SUB+=	DBDIR=${DBDIR} LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib \
		--with-dbdir=${DBDIR} \
		--with-zlib=/usr \
		--disable-clamuko \
		--disable-clamav \
		--enable-bigstack \
		--enable-readdir_r \
		--enable-gethostbyname_r \
		--disable-dependency-tracking \
		--enable-experimental
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}

# This port has a problem with -pthread,
# force to use -lthr until it's not fixed.
PTHREAD_LIBS=	-lthr

MAN1=		clamconf.1 \
		clamscan.1 \
		freshclam.1 \
		sigtool.1 \
		clamdscan.1 \
		clamdtop.1
MAN5=		clamd.conf.5 \
		freshclam.conf.5
MAN8=		clamd.8 \
		clamav-milter.8

CONFLICTS=	clamav-0.[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav

CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd.sock
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP} \
		CLAMAV_CLAMD_SOCKET=${CLAMAV_CLAMD_SOCKET} \
		CLAMAV_MILTER_SOCKET=${CLAMAV_MILTER_SOCKET} \
		CHMOD=${CHMOD} \
		CHOWN=${CHOWN}

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z\-]+\.pid)$$|\1 ${RUNDIR}/\2|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(AllowSupplementaryGroups).*$$|\1 yes|' \
		-e 's|^\#?(ScanMail).*$$|\1 yes|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DBDIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(FixStaleSocket).*$$|\1 yes|' \
		-e 's|^\#?(NotifyClamd) .*$$|\1 ${PREFIX}/etc/clamd.conf|' \
		-e 's|^\#?(MilterSocket) */tmp.*$$|\1 ${CLAMAV_MILTER_SOCKET}|' \
		-e 's|^\#?(ClamdSocket).*$$|\1 unix:${CLAMAV_CLAMD_SOCKET}|'

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

.include <bsd.port.pre.mk>

.if defined(WITH_ARC)
RUN_DEPENDS+=	arc:${PORTSDIR}/archivers/arc
.endif
.if defined(WITH_ARJ)
RUN_DEPENDS+=	arj:${PORTSDIR}/archivers/arj
.endif
.if defined(WITH_LHA)
RUN_DEPENDS+=	lha:${PORTSDIR}/archivers/lha
.endif
.if defined(WITH_UNZOO)
RUN_DEPENDS+=	unzoo:${PORTSDIR}/archivers/unzoo
.endif
.if defined(WITH_UNRAR)
PLIST_SUB+=	UNRAR=""
.else
PLIST_SUB+=	UNRAR="@comment "
CONFIGURE_ARGS+=	--disable-unrar
.endif
.if defined(WITH_ICONV)
CONFIGURE_ARGS+=--with-iconv
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=--without-iconv
.endif

.if defined(WITH_MILTER)
USE_RC_SUBR+=	clamav-milter
CONF_FILES+=	clamav-milter
. if defined(WITH_LDAP) && exists(${LOCALBASE}/lib/libldap.so)
USE_OPENLDAP=	yes
LDFLAGS+=	-lldap
. endif

. if !exists(/usr/lib/libmilter.a) || exists(${LOCALBASE}/lib/libmilter.a)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
CONFIGURE_ARGS+=	--with-sendmail=${LOCALBASE}/sbin/sendmail
. else
CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
. endif

CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER=""
.else
PLIST_SUB+=	CLAMAV-MILTER="@comment "
.endif

.if defined(WITH_STDERR)
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-shared_output.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,^\(pkgconfigdir = \).*$$,\1$$\(prefix\)/libdata/pkgconfig,g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} ${SED_CONF} \
		${WRKSRC}/etc/clamd.conf \
		${WRKSRC}/etc/freshclam.conf \
		${WRKSRC}/etc/clamav-milter.conf
	@${REINPLACE_CMD} -e 's|0x100000000|0x100000000ULL|g' \
		${WRKSRC}/libclamunrar/unrar.c

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/clamav-config.h ${PREFIX}/include
.for c in ${CONF_FILES}
	@[ -f ${PREFIX}/etc/${c}.conf ] || \
		${CP} -v ${PREFIX}/etc/${c}.conf.default ${PREFIX}/etc/${c}.conf
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}/html
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
