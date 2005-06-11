# New ports collection makefile for:	ipw-firmware
# Date created:				May 11 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	ipw-firmware
RELNAME?=	ipw2100
PORTVERSION?=	1.3
PORTREVISION?=	1
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/ipw
DISTFILES=	${RELNAME}-fw-${PORTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Intel PRO/Wireless 2100 Driver Firmware

DRIVERNAME?=	ipw
DRIVERVERSION?=	1.6.4
DRIVERDISTNAME=	${DRIVERNAME}-freebsd-${DRIVERVERSION}
DISTFILES+=	${DRIVERDISTNAME}.tgz
FIRMWARES?=	${RELNAME}-${PORTVERSION}-i.fw ${RELNAME}-${PORTVERSION}-p.fw ${RELNAME}-${PORTVERSION}.fw

OPTIONS=	MODULE	"Install ${DRIVERNAME}(4) kernel module"	off

WRKSRC=		${WRKDIR}
KERNDIR=	/boot/kernel
KMODDIR=	/boot/modules
SUB_FILES=	pkg-message
SUB_LIST=	DRIVERNAME="${DRIVERNAME}" \
		RELNAME="${RELNAME}" \
		PORTVERSION="${PORTVERSION}" \
		KMODDIR="${KMODDIR}"
PLIST_SUB:=	${SUB_LIST}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man" \
		KMODDIR="${KMODDIR}"
USE_RC_SUBR=	${DRIVERNAME}.sh

MAN8=		${DRIVERNAME}control.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

# That's a bit arbitrary since I have no idea if ${DRIVERNAME}(4) can be
# compiled on FreeBSD previous to 5.3-RELEASE. This is just too old, people
# should move on. I may change this if I get successful reports though.
# Comment this IGNORE line if you want to test it anyway.
.if ${OSVERSION} < 503000
IGNORE=		Need a fresh version of RELENG_5
.endif

.if defined(WITH_MODULE)
. if ${OSVERSION} > 600023
IGNORE=		${DRIVERNAME}(4) support is already included in your tree
. else
PLIST_SUB+=	WITH_MODULE=""
MAN4+=		${DRIVERNAME}.4
. endif
.else
PLIST_SUB+=	WITH_MODULE="@comment MODULE "
.endif

# "Might" because people still can include ${DRIVERNAME}(4) support in kernel by extracting
# its source in src/ and tweaking src/sys/conf/files.
.if ${OSVERSION} <= 600023 && !exists(${KERNDIR}/if_${DRIVERNAME}.ko) && !defined(WITH_MODULE)
SUB_LIST+=	MIGHT_NEED_MODULE=""
.else
SUB_LIST+=	MIGHT_NEED_MODULE="@comment "
.endif

do-build:
.if defined(WITH_MODULE)
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/; make all
.else
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/usr.sbin/${DRIVERNAME}control/; make all
.endif

do-install:
.if !defined(PACKAGE_BUILDING)
# Let pointyhat build the package, anyway the user will have to agree with license
# terms to install the port/package.
	${SH} ${PKGREQ} ${PORTNAME} INSTALL
.endif
	${MKDIR} ${DATADIR}
.if defined(WITH_MODULE)
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/; make install ${MAKE_ENV}
.else
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/usr.sbin/${DRIVERNAME}control/; make install ${MAKE_ENV}
.endif
.for i in LICENSE ${FIRMWARES}
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
