# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.88.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	clamav

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Command line virus scanner written entirely in C

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

OPTIONS=	MILTER "Compile the milter interface" Off \
		CURL "Support URL downloading" Off \
		LIBUNRAR "Support for external Unrar library" Off

USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	clamav-clamd clamav-freshclam

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
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamd.conf.5 freshclam.conf.5
MAN8=		clamd.8 clamav-milter.8

CONFLICTS=	clamav-devel-[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav
CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP} \
		CLAMAV_CLAMD_SOCKET=${CLAMAV_CLAMD_SOCKET} \
		CLAMAV_MILTER_SOCKET=${CLAMAV_MILTER_SOCKET}

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z]+\.pid)$$|\1 ${RUNDIR}/\2|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(AllowSupplementaryGroups)$$|\1|' \
		-e 's|^\#?(ScanMail)$$|\1|' \
		-e 's|^\#?(NotifyClamd)$$|\1|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DBDIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(FixStaleSocket)$$|\1|'

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

.include <bsd.port.pre.mk>

.if ${OSVERSION} == 502010
PTHREAD_LIBS=	-pthread
.endif

.if defined(WITH_MILTER)
USE_RC_SUBR+=	clamav-milter
.if !defined(WITHOUT_LDAP) && exists(${LOCALBASE}/lib/libldap.so)
USE_OPENLDAP=	yes
LDFLAGS+=	-lldap
.endif
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

.if defined(WITH_LIBUNRAR)
CFLAGS+=		-DUNRAR3
LDFLAGS+=		-lunrar
LIB_DEPENDS+=		unrar.3:${PORTSDIR}/archivers/libunrar
EXTRA_PATCHES=		${FILESDIR}/extra-patch-libunrar
.else
RUN_DEPENDS+=		unrar:${PORTSDIR}/archivers/unrar
EXTRA_PATCHES=		${FILESDIR}/extra-patch-libclamav__unrarlib.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread -lc_r|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-build:
	@if ${LDCONFIG} -r | ${GREP} -qw -e -lclamav; then \
		${ECHO_MSG} "===>  *** WARNING ***"; \
		${ECHO_MSG} "      Installed version of libclamav found."; \
		${ECHO_MSG} "      This might cause build problems."; \
	fi

post-build:
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamd.conf
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/freshclam.conf

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} PKG_DESTDIR=${DESTDIR} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:
	@${CHOWN} -R ${CLAMAVUSER}:${CLAMAVGROUP} ${DESTDIR}${DBDIR}
.for c in clamd freshclam
	@[ -f ${DESTDIR}${PREFIX}/etc/${c}.conf ] || \
		${CP} ${DESTDIR}${PREFIX}/etc/${c}.conf.default ${DESTDIR}${PREFIX}/etc/${c}.conf
.endfor
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
