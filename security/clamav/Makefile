# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	${DISTVERSION:S/-rc//g:S/-/./g}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	clamav
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	rob@debank.tv
COMMENT=	Command line virus scanner written entirely in C

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

DISTVERSION=	0.75.1

OPTIONS=	MILTER "Compile the milter interface" off
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORTDOCS=	NEWS ChangeLog html

CONFIGURE_ARGS=	--with-dbdir=${DATADIR} \
		--disable-clamuko \
		--disable-clamav \
		--enable-bigstack \
		--disable-dependency-tracking
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamav.conf.5 freshclam.conf.5
MAN8=		clamd.8 clamav-milter.8

CONFLICTS=	clamav-devel-[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav
CLAMAV_CLAMD_SOCKET?=	/var/run/clamav/clamd
CLAMAV_MILTER_SOCKET?=	/var/run/clamav/clmilter.sock

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%CLAMAVUSER%%|${CLAMAVUSER}|g' \
		-e 's|%%CLAMAVGROUP%%|${CLAMAVGROUP}|g' \
		-e 's|%%CLAMAV_CLAMD_SOCKET%%|${CLAMAV_CLAMD_SOCKET}|g' \
		-e 's|%%CLAMAV_MILTER_SOCKET%%|${CLAMAV_MILTER_SOCKET}|g'

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?(LogFile) .*$$|\1 /var/log/clamav/clamd.log|' \
		-e 's|^\#?(PidFile) .*$$|\1 /var/run/clamav/clamd.pid|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(AllowSupplementaryGroups)$$|\1|' \
		-e 's|^\#?(ScanMail)$$|\1|' \
		-e 's|^\#?(Checks)$$|\#\1|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DATADIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(UpdateLogFile) .*$$|\1 /var/log/clamav/freshclam.log|' \
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
.endif
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER=""
.else
PLIST_SUB+=	CLAMAV-MILTER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread -lc_r|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/usr/lib/sendmail|/usr/sbin/sendmail|g' \
		${WRKSRC}/clamav-milter/clamav-milter.c
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-build:
	@${REINPLACE_CMD} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamav.conf
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
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-clamd.sh \
		${RC_DIR}/clamav-clamd${RC_SUFX}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-freshclam.sh \
		${RC_DIR}/clamav-freshclam${RC_SUFX}
	@${CHOWN} -R ${CLAMAVUSER}:${CLAMAVGROUP} ${DATADIR}
.for c in clamav freshclam
	@[ -f ${PREFIX}/etc/${c}.conf ] || \
		${CP} ${PREFIX}/etc/${c}.conf.default ${PREFIX}/etc/${c}.conf
.endfor
.if defined(WITH_MILTER)
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-milter.sh \
		${RC_DIR}/clamav-milter${RC_SUFX}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/NEWS ${INSTALL_WRKSRC}/ChangeLog \
		${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/html/*.* \
		${DOCSDIR}/html
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
