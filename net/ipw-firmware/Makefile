# New ports collection makefile for:	ipw-firmware
# Date created:				May 11 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	ipw-firmware
RELNAME?=	ipw2100
PORTVERSION?=	1.3
PORTREVISION?=	7
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/ipw
DISTFILES=	${RELNAME}-fw-${PORTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT?=	Intel PRO/Wireless 2100 Driver Firmware

DRIVERNAME?=	ipw
DRIVERVERSION?=	1.6.4
DRIVERDISTNAME=	${DRIVERNAME}-freebsd-${DRIVERVERSION}
DISTFILES+=	${DRIVERDISTNAME}.tgz
FIRMWARES?=	${RELNAME}-${PORTVERSION}-i.fw:${DRIVERNAME}-i.fw \
		${RELNAME}-${PORTVERSION}-p.fw:${DRIVERNAME}-p.fw \
		${RELNAME}-${PORTVERSION}.fw:${DRIVERNAME}.fw

OPTIONS=	MODULE	"Install ${DRIVERNAME}(4) kernel module (very old snapshot)" off \
		CONTROL	"Install ${DRIVERNAME}control(8) utility" on

# Override PREFIX to install ${DRIVERNAME}control(8) somewhere we hope it'll
# be available soon enough.
PREFIX=		/usr

WRKSRC=		${WRKDIR}
KERNDIR=	/boot/kernel
KMODDIR=	/boot/modules
FWDIR=		/boot/firmware
SUB_FILES=	pkg-message
SUB_LIST=	DRIVERNAME="${DRIVERNAME}" \
		RELNAME="${RELNAME}" \
		KMODDIR="${KMODDIR}" \
		FWDIR="${FWDIR}"
PLIST_SUB:=	${SUB_LIST}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/share/man/man" \
		KMODDIR="${KMODDIR}"

MANCOMPRESSED=	yes

# Dummy OSVERSION for ipw.
MIN7OSVERSION?=	999999

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

# That's a bit arbitrary since I have no idea if ${DRIVERNAME}(4) can be
# compiled on FreeBSD previous to 5.3-RELEASE. This is just too old, people
# should move on. I may change this if I get successful reports though.
# Comment this IGNORE line if you want to test it anyway.
.if ${OSVERSION} < 503000
IGNORE=		needs at least FreeBSD 5.3-RELEASE
.endif

.if ( ${OSVERSION} >= 700014 )
IGNORE=		is now obsolete, install net/${DRIVERNAME}-firmware-kmod instead
.endif


.if ${OSVERSION} > ${MIN7OSVERSION}
SUB_LIST+=	DONT_NEED_CONTROL="@comment "
MTREE_DIRRM=	"@comment "
. if !defined(WITHOUT_CONTROL)
IGNORE=		is configured with ${DRIVERNAME}control(8) which you don't need
. endif
.else
SUB_LIST+=	DONT_NEED_CONTROL=""
MTREE_DIRRM=	""
MAN8+=		${DRIVERNAME}control.8
USE_RCORDER=	${DRIVERNAME}.sh
.endif

# Hack because ipw(4) and iwi(4) behavior are not in sync: as of 20/01/2006,
# iwi(4) loads firmware from /boot/firmware, but ipw(4) does not). Hopefully,
# sam or mlaier will commit generic firmware loading support and new firmware
# ports will be created once ipw(4) and iwi(4) have been patched to use it.
.if ${DRIVERNAME} == "ipw" && ${OSVERSION} > 700006
MTREE_DIRRM=	"@comment "
.endif

PLIST_SUB+=	MTREE_DIRRM=${MTREE_DIRRM}

.if defined(WITH_MODULE)
. if ${OSVERSION} > 600023
IGNORE=		is configured with ${DRIVERNAME}(4) support which you don't need
. else
PLIST_SUB+=	WITH_MODULE=""
MAN4+=		${DRIVERNAME}.4
. endif
.else
PLIST_SUB+=	WITH_MODULE="@comment MODULE "
.endif

.if !defined(WITHOUT_CONTROL)
PLIST_SUB+=	WITH_CONTROL=""
.else
PLIST_SUB+=	WITH_CONTROL="@comment CONTROL "
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
. for i in share sys
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/${i}; make all
. endfor
.endif
.if !defined(WITHOUT_CONTROL)
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/usr.sbin/${DRIVERNAME}control/; make all
.endif

do-install:
.if !defined(PACKAGE_BUILDING)
# Let pointyhat build the package, anyway the user will have to agree with license
# terms to install the port/package.
	${SH} ${PKGREQ} ${PORTNAME} INSTALL
.endif
.if defined(WITH_MODULE)
. for i in share sys
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/${i}; make install ${MAKE_ENV}
. endfor
.endif
.if !defined(WITHOUT_CONTROL)
	cd ${WRKSRC}/${DRIVERDISTNAME}/src/usr.sbin/${DRIVERNAME}control/; make install ${MAKE_ENV}
.endif
	${MKDIR} ${FWDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${FWDIR}/LICENSE.${DRIVERNAME}
.for i in ${FIRMWARES}
	${INSTALL_DATA} ${WRKSRC}/${i:C/:.*//} ${FWDIR}/${i:C/.*://}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_MODULE)
	@${ECHO_CMD} "You asked for ${DRIVERNAME}(4) module to be installed but"
	@${ECHO_CMD} "be aware that this is a *very* *old* snapshot of the code"
	@${ECHO_CMD} "and that it probably won't work correctly."
	@${ECHO_CMD} "This option will probably go away in a near future."
	@${ECHO_CMD} "SLIPPERY WHEN WET ! BEWARE OF THE DOGS !"
	@${ECHO_CMD} "You have been warned."
.endif


.include <bsd.port.post.mk>
