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

WRKSRC=		${WRKDIR}
SUB_FILES=	pkg-message
SUB_LIST=	PORTVERSION="${PORTVERSION}"
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"
USE_RC_SUBR=	ipw.sh

MAN8=		ipwcontrol.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/usr.sbin/ipwcontrol/; make all

do-install:
.if !defined(PACKAGE_BUILDING)
# Let pointyhat build the package, anyway the user will have to agree with license
# terms to install the port/package.
	${SH} ${PKGREQ} ${PORTNAME} INSTALL
.endif
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/ipw-freebsd-${IPW_VERSION}/src/usr.sbin/ipwcontrol/; make install ${MAKE_ENV}
.for i in LICENSE ipw2100-1.3-i.fw ipw2100-1.3-p.fw ipw2100-1.3.fw
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
