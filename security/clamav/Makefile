# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.65
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clamav

MAINTAINER=	markun@onohara.to
COMMENT=	Command line virus scanner written entirely in C

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=14
INSTALLS_SHLIB=	yes

PKGINSTALL=	${WRKDIR}/pkg-install

CONFIGURE_ARGS=	--with-dbdir=${DATADIR} \
		--disable-clamav --enable-bigstack
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamav.conf.5
MAN8=		clamd.8 clamav-milter.8

CLAMAV_CLAMD_SOCKET?=	/var/run/clamav/clamd
CLAMAV_MILTER_SOCKET?=	/var/run/clmilter.sock

CONFLICTS=	clamav-devel-*

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%CLAMAV_CLAMD_SOCKET%%|${CLAMAV_CLAMD_SOCKET}|g' \
		-e 's|%%CLAMAV_MILTER_SOCKET%%|${CLAMAV_MILTER_SOCKET}|g'

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?(LogFile) .*$$|\1 /var/log/clamav/clamd.log|' \
		-e 's|^\#?(PidFile) .*$$|\1 /var/run/clamav/clamd.pid|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 clamav|' \
		-e 's|^\#?(AllowSupplementaryGroups)$$|\1|' \
		-e 's|^\#?(ScanMail)$$|\1|'

.include <bsd.port.pre.mk>

USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'
PLIST_SUB+=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

.if defined(WITH_MILTER)
.if exists(${LOCALBASE}/lib/libmilter.a)
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
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

pre-configure:
	@${REINPLACE_CMD} -e 's|clamav.conf|&.default|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${CONFIGURE_WRKSRC}/etc/Makefile.in
.ifdef USE_LIBTOOL_VER
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s|\$$(top_builddir)/libtool|${LIBTOOL}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-build:
	@${SED} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamav.conf \
		>${BUILD_WRKSRC}/etc/clamav.conf.default
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install >${PKGINSTALL}
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
	@${INSTALL_DATA} ${BUILD_WRKSRC}/etc/clamav.conf.default \
		${PREFIX}/etc/clamav.conf.default
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-clamd.sh \
		${RC_DIR}/clamav-clamd${RC_SUFX}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-freshclam.sh \
		${RC_DIR}/clamav-freshclam${RC_SUFX}
	@${CHOWN} -R clamav:clamav ${DATADIR}
	@[ -f ${PREFIX}/etc/clamav.conf ] || \
		${CP} ${PREFIX}/etc/clamav.conf.default ${PREFIX}/etc/clamav.conf
.if defined(WITH_MILTER)
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-milter.sh \
		${RC_DIR}/clamav-milter${RC_SUFX}
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
