# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20050524
CATEGORIES=	security
MASTER_SITES=	http://www.clamav.net/snapshot/ \
		http://www.galle.com.br/~renato/clamav-devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	rob@debank.tv
COMMENT=	Command line virus scanner written entirely in C

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

OPTIONS=	MILTER "Compile the milter interface" Off \
		CURL "Support URL downloading" Off

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOCONF_VER=259
USE_AUTOMAKE_VER=19
USE_LIBTOOL_VER=15
LIBTOOLFILES=	acinclude.m4
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORTDOCS=	NEWS ChangeLog html

DBDIR=		/var/db/clamav
LOGDIR=		/var/log/clamav
RUNDIR=		/var/run/clamav
PLIST_SUB+=	DBDIR=${DBDIR} LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

CONFIGURE_ARGS=	--with-dbdir=${DBDIR} \
		--with-zlib=/usr \
		--disable-zlib-vcheck \
		--disable-clamuko \
		--disable-clamav \
		--enable-bigstack \
		--disable-gethostbyname_r \
		--enable-readdir_r \
		--disable-dependency-tracking
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamd.conf.5 freshclam.conf.5
MAN8=		clamd.8 clamav-milter.8

CONFLICTS=	clamav-0.[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav
CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DBDIR%%|${DBDIR}|g' \
		-e 's|%%LOGDIR%%|${LOGDIR}|g' \
		-e 's|%%RUNDIR%%|${RUNDIR}|g' \
		-e 's|%%CLAMAVUSER%%|${CLAMAVUSER}|g' \
		-e 's|%%CLAMAVGROUP%%|${CLAMAVGROUP}|g' \
		-e 's|%%CLAMAV_CLAMD_SOCKET%%|${CLAMAV_CLAMD_SOCKET}|g' \
		-e 's|%%CLAMAV_MILTER_SOCKET%%|${CLAMAV_MILTER_SOCKET}|g'

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z]+\.pid)$$|\1 ${RUNDIR}/\2|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(AllowSupplementaryGroups)$$|\1|' \
		-e 's|^\#?(ScanMail)$$|\1|' \
		-e 's|^\#?(NotifyClamd)$$|\1|' \
		-e 's|^\#?(Checks)$$|\#\1|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DBDIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(FixStaleSocket)$$|\1|'

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'
PLIST_SUB+=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

.include <bsd.port.pre.mk>

.if defined(WITH_MILTER)
.if !exists(/usr/lib/libmilter.a)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
CONFIGURE_ENV+=	SENDMAIL="${LOCALBASE}/sbin/sendmail"
.else
CONFIGURE_ENV+=	SENDMAIL="/usr/sbin/sendmail"
.endif
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER=""
.else
PLIST_SUB+=	CLAMAV-MILTER="@comment "
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=		curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libcurl
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

pre-build:
	@if ${LDCONFIG} -r | ${GREP} -qw -e -lclamav; then \
		${ECHO_MSG} "===>  *** WARNING ***"; \
		${ECHO_MSG} "      Installed version of libclamav found."; \
		${ECHO_MSG} "      This might cause build problems."; \
	fi

post-build:
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamd.conf
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/freshclam.conf
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install >${PKGINSTALL}
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-deinstall >${PKGDEINSTALL}
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-clamd.sh \
		>${WRKDIR}/clamav-clamd.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-freshclam.sh \
		>${WRKDIR}/clamav-freshclam.sh
.if defined(WITH_MILTER)
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-milter.sh \
		>${WRKDIR}/clamav-milter.sh
.endif

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} PKG_DESTDIR=${DESTDIR} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-clamd.sh \
		${DESTDIR}${RC_DIR}/clamav-clamd${RC_SUFX}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-freshclam.sh \
		${DESTDIR}${RC_DIR}/clamav-freshclam${RC_SUFX}
	@${CHOWN} -R ${CLAMAVUSER}:${CLAMAVGROUP} ${DESTDIR}${DBDIR}
.for c in clamd freshclam
	@[ -f ${DESTDIR}${PREFIX}/etc/${c}.conf ] || \
		${CP} ${DESTDIR}${PREFIX}/etc/${c}.conf.default ${DESTDIR}${PREFIX}/etc/${c}.conf
.endfor
.if defined(WITH_MILTER)
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-milter.sh \
		${DESTDIR}${RC_DIR}/clamav-milter${RC_SUFX}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/NEWS ${INSTALL_WRKSRC}/ChangeLog \
		${DESTDIR}${DOCSDIR}
	@${MKDIR} ${DESTDIR}${DOCSDIR}/html
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/html/*.* \
		${DESTDIR}${DOCSDIR}/html
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} PKG_DESTDIR=${DESTDIR} \
		${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
