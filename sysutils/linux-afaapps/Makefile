# New ports collection makefile for:	linux-afaapps
# Date created:				6 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		afaapps
PORTVERSION=		2.7
PORTREVISION=		4
CATEGORIES=		sysutils linux
MASTER_SITES=		ftp://ftp.us.dell.com/scsi-raid/
PKGNAMEPREFIX=		linux-
DISTNAME=		aacraid-util-rh8.0-${MACHINE_ARCH}

MAINTAINER=		bms@FreeBSD.org
COMMENT=		DELL PowerEdge Raid Controller 2 (apps)

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=		${LINUXBASE}/usr/lib/libartsc.so.0:${PORTSDIR}/audio/linux-arts

BROKEN=			Incomplete pkg-plist
DEPRECATED=		${BROKEN}
EXPIRATION_DATE=	2005-09-22

RESTRICTED=		"binary redistribution license needs clarification"

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

USE_LINUX=		yes
USE_LINUX_PREFIX=       yes
LDCONFIG_LINUX=		${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=		i386
PLIST=			${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

RPMFILE=		${PORTNAME}-${PORTVERSION}-2.${MACHINE_ARCH}.rpm

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--nodeps --replacepkgs --noscripts

do-install:
	@${LOCALBASE}/bin/rpm -U ${RPMFLAGS} ${WRKDIR}/${RPMFILE}
	@${RM} ${PREFIX}/usr/sbin/afacli
	@${MV} ${PREFIX}/usr/sbin/afacli.bin ${PREFIX}/usr/sbin/afacli
	@${BRANDELF} -t Linux ${PREFIX}/usr/sbin/afacli
	@${LDCONFIG_LINUX}

.include <bsd.port.mk>
