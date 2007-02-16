# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.90
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Command line virus scanner written entirely in C

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		arj:${PORTSDIR}/archivers/arj \
		unzoo:${PORTSDIR}/archivers/unzoo \
		arc:${PORTSDIR}/archivers/arc

OPTIONS=	MILTER "Compile the milter interface" Off \
		LDAP "libmilter was built with LDAP" Off \
		CURL "Support URL downloading" Off \
		STDERR "Print logs to stderr instead of stdout" Off

USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes
USE_RC_SUBR=	clamav-clamd clamav-freshclam

PORTDOCS=	*

DBDIR=		/var/db/clamav
LOGDIR=		/var/log/clamav
RUNDIR=		/var/run/clamav
PLIST_SUB+=	DBDIR=${DBDIR} LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

CONFIGURE_ARGS=	--with-dbdir=${DBDIR} \
		--with-zlib=/usr \
		--mandir=${MANPREFIX:S/^${DESTDIR}//}/man \
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
MAN1=		clamconf.1 \
		clamscan.1 \
		freshclam.1 \
		sigtool.1 \
		clamdscan.1
MAN5=		clamd.conf.5 \
		freshclam.conf.5
MAN8=		clamd.8 \
		clamav-milter.8

CONFLICTS=	clamav-devel-[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav

CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DESTDIR=${DESTDIR} \
		DBDIR=${DBDIR} \
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
		-e 's|^\#?(AllowSupplementaryGroups).*$$|\1 yes|' \
		-e 's|^\#?(ScanMail).*$$|\1 yes|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DBDIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(FixStaleSocket).*$$|\1 yes|' \
		-e 's|^\#?(NotifyClamd) .*$$|\1 ${PREFIX}/etc/clamd.conf|'

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

.include <bsd.port.pre.mk>

.if ${OSVERSION} == 502010
PTHREAD_LIBS=	-pthread
.endif

.if defined(WITH_MILTER)
USE_RC_SUBR+=	clamav-milter
.if defined(WITH_LDAP) && exists(${LOCALBASE}/lib/libldap.so)
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
LIB_DEPENDS+=		curl.4:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libcurl
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

.if defined(WITH_STDERR)
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-shared_output.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread -lc_r|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,unarj,arj,g' \
		${WRKSRC}/docs/man/clamscan.1
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamd.conf
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/freshclam.conf

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for c in clamd freshclam
	@[ -f ${TARGETDIR}/etc/${c}.conf ] || \
		${CP} ${TARGETDIR}/etc/${c}.conf.default ${TARGETDIR}/etc/${c}.conf
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/NEWS ${INSTALL_WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/html/* ${DOCSDIR}/html
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
