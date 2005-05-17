# New ports collection makefile for:	ipw-firmware
# Date created:				May 11 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipw-firmware
PORTVERSION=	1.3
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/ipw
DISTFILES=	ipw2100-fw-${PORTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Intel PRO/Wireless 2100 Driver Firmware

IPW_VERSION=	1.6.4
DISTFILES+=	ipw-freebsd-${IPW_VERSION}.tgz

OPTIONS=	MODULE	"Install ipw(4) kernel module"	off

WRKSRC=		${WRKDIR}
SUB_FILES=	pkg-message
SUB_LIST=	PORTVERSION="${PORTVERSION}"
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man" \
		KMODDIR="/boot/modules"
USE_RC_SUBR=	ipw.sh

MAN8=		ipwcontrol.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

# That's a bit arbitrary since I have no idea if ipw(4) can be compiled on FreeBSD
# previous to 5.3-RELEASE. This is just too old, people should move on.
# I may change this if I get successful reports though.
# Comment this if you want to test it anyway.
.if ${OSVERSION} < 503000
IGNORE=		Need a fresh version of RELENG_5
.endif

.if defined(WITH_MODULE)
. if ${OSVERSION} > 600023
IGNORE=		ipw(4) support is already included in your tree
. else
PLIST_SUB+=	IF_IPW_KO=""
MAN4+=		ipw.4
. endif
.else
PLIST_SUB+=	IF_IPW_KO="@comment "
.endif

# "Might" because people still can include ipw(4) support in kernel by extracting
# its source in src/ and tweaking src/sys/conf/files.
.if ${OSVERSION} <= 600023 && !exists(/boot/modules/if_ipw.ko) && !defined(WITH_MODULE)
SUB_LIST+=	MIGHT_NEED_MODULE=""
.else
SUB_LIST+=	MIGHT_NEED_MODULE="@comment "
.endif

do-build:
.if defined(WITH_MODULE)
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/; make all
.else
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/usr.sbin/ipwcontrol/; make all
.endif

do-install:
.if !defined(PACKAGE_BUILDING)
# Let pointyhat build the package, anyway the user will have to agree with license
# terms to install the port/package.
	${SH} ${PKGREQ} ${PORTNAME} INSTALL
.endif
	${MKDIR} ${DATADIR}
.if defined(WITH_MODULE)
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/; make install ${MAKE_ENV}
.else
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/usr.sbin/ipwcontrol/; make install ${MAKE_ENV}
.endif
.for i in LICENSE ipw2100-1.3-i.fw ipw2100-1.3-p.fw ipw2100-1.3.fw
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
