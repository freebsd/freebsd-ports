# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20031001
CATEGORIES=	security
MASTER_SITES=	http://clamav.sourceforge.net/snapshot/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	rob@debank.tv
COMMENT=	Command line virus scanner written entirely in C

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-dbdir=${DATADIR} \
		--disable-clamav --enable-bigstack
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1 clamav-milter.1
MAN5=		clamav.conf.5
MAN8=		clamd.8

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav
CLAMAV_CLAMD_SOCKET?=	/var/run/clamav/clamd
CLAMAV_MILTER_SOCKET?=	/var/run/clmilter.sock

PLIST_SUB+=	CLAMAVUSER="${CLAMAVUSER}"
PLIST_SUB+=	CLAMAVGROUP="${CLAMAVGROUP}"

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%CLAMAVUSER%%|${CLAMAVUSER}|g' \
		-e 's|%%CLAMAVGROUP%%|${CLAMAVGROUP}|g' \
		-e 's|%%CLAMAV_CLAMD_SOCKET%%|${CLAMAV_CLAMD_SOCKET}|g' \
		-e 's|%%CLAMAV_MILTER_SOCKET%%|${CLAMAV_MILTER_SOCKET}|g'

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?(LogFile) .*$$|\1 /var/log/clamav/clamd.log|' \
		-e 's|^\#?(PidFile) .*$$|\1 /var/run/clamav/clamd.pid|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 /var/run/clamav/clamd|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
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

.if ${OSVERSION} < 501001
# compiles only with optimizer
CFLAGS+=	-O
LDFLAGS+=	-lcipher
.endif

.if defined(WITH_MILTER)
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER:=""
.else
PLIST_SUB+=	CLAMAV-MILTER:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib/sendmail|/usr/sbin/sendmail|g' \
		${WRKSRC}/clamav-milter/clamav-milter.c

pre-configure:
	@${REINPLACE_CMD} -e 's|clamav.conf|&.default|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${CONFIGURE_WRKSRC}/etc/Makefile.in

post-build:
	@${SED} ${SED_CONF} ${BUILD_WRKSRC}/etc/clamav.conf \
		> ${BUILD_WRKSRC}/etc/clamav.conf.default
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-clamd.sh \
		> ${WRKDIR}/clamav-clamd.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/clamav-milter.sh \
		> ${WRKDIR}/clamav-milter.sh

pre-install:
	 ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:
	@[ -f ${PREFIX}/etc/clamav.conf ] || \
		${CP} ${PREFIX}/etc/clamav.conf.default \
			${PREFIX}/etc/clamav.conf
	@${CHOWN} -R ${CLAMAVUSER}:${CLAMAVGROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-clamd.sh \
		${RC_DIR}/clamav-clamd${RC_SUFX}
.if defined(WITH_MILTER)
	@${INSTALL_SCRIPT} ${WRKDIR}/clamav-milter.sh \
		${RC_DIR}/clamav-milter${RC_SUFX}
.endif

.include <bsd.port.post.mk>
