# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20040609
CATEGORIES=	security
MASTER_SITES=	http://clamav.sourceforge.net/snapshot/
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

OPTIONS=	MILTER "Compile the milter interface" off
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOCONF_VER=259
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes

CONFIGURE_ARGS=	--with-dbdir=${DATADIR} \
		--disable-clamuko \
		--disable-clamav \
		--enable-bigstack \
		--disable-dependency-tracking
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" "CPPFLAGS=${CPPFLAGS}"

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamav.conf.5 freshclam.conf.5
MAN8=		clamd.8 clamav-milter.8

CONFLICTS=	clamav-0.*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav
CLAMAV_CLAMD_SOCKET?=	/var/run/clamav/clamd
CLAMAV_MILTER_SOCKET?=	/var/run/clamav/clmilter.sock
DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

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

.if ${OSVERSION} < 501001
# compiles only with libcipher
LDFLAGS+=	-lcipher
.endif

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
	@${REINPLACE_CMD} -e 's|/usr/lib/sendmail|/usr/sbin/sendmail|g' \
		${WRKSRC}/clamav-milter/clamav-milter.c

post-build:
	@${SED} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamav.conf \
		> ${BUILD_WRKSRC}/etc/clamav.conf.default
	@${CP} ${BUILD_WRKSRC}/etc/clamav.conf.default \
		${BUILD_WRKSRC}/etc/clamav.conf
	@${SED} ${SED_CONF} ${BUILD_WRKSRC}/etc/freshclam.conf \
		> ${BUILD_WRKSRC}/etc/freshclam.conf.default
	@${CP} ${BUILD_WRKSRC}/etc/freshclam.conf.default \
		${BUILD_WRKSRC}/etc/freshclam.conf
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-clamd.sh \
		> ${WRKDIR}/clamav-clamd.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-milter.sh \
		> ${WRKDIR}/clamav-milter.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-freshclam.sh \
		> ${WRKDIR}/clamav-freshclam.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*pdf ${DOCSDIR}
.endif

post-install:
	@[ -f ${PREFIX}/etc/clamav.conf ] || \
		${CP} ${BUILD_WRKSRC}/etc/clamav.conf.default \
			${PREFIX}/etc/clamav.conf
	@[ -f ${PREFIX}/etc/clamav.conf.default ] || \
		${CP} ${BUILD_WRKSRC}/etc/clamav.conf.default \
			${PREFIX}/etc/clamav.conf.default
	@[ -f ${PREFIX}/etc/freshclam.conf ] || \
		${CP} ${BUILD_WRKSRC}/etc/freshclam.conf.default \
			${PREFIX}/etc/freshclam.conf
	@[ -f ${PREFIX}/etc/freshclam.conf.default ] || \
		${CP} ${BUILD_WRKSRC}/etc/freshclam.conf.default \
			${PREFIX}/etc/freshclam.conf.default
	@${CHOWN} -R ${CLAMAVUSER}:${CLAMAVGROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-clamd.sh \
		${RC_DIR}/clamav-clamd${RC_SUFX}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-freshclam.sh \
		${RC_DIR}/clamav-freshclam${RC_SUFX}
.if defined(WITH_MILTER)
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-milter.sh \
		${RC_DIR}/clamav-milter${RC_SUFX}
.endif

.include <bsd.port.post.mk>
