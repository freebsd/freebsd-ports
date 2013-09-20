# Created by: bms@FreeBSD.org
# $FreeBSD$

PORTNAME=		afaapps
PORTVERSION=		2.7
PORTREVISION=		4
CATEGORIES=		sysutils linux
MASTER_SITES=		ftp://ftp.us.dell.com/scsi-raid/
PKGNAMEPREFIX=		linux-
DISTNAME=		aacraid-util-rh8.0-${LINUX_RPM_ARCH}
DIST_SUBDIR=		rpm

MAINTAINER=		ports@FreeBSD.org
COMMENT=		DELL PowerEdge Raid Controller 2 (apps)

RESTRICTED=		binary redistribution license needs clarification

EXTRACT_SUFX=	.tar.gz

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	arts
ONLY_FOR_ARCHS=	i386 amd64
BRANDELF_FILES=	usr/sbin/afacli
SRC_DISTFILES=	# empty, no sources available

RPMFILE=	${PORTNAME}-${PORTVERSION}-2.${LINUX_RPM_ARCH}.rpm
EXTRACT_AFTER_ARGS=	-O ${RPMFILE} | ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} - ./usr/sbin/afacli.bin ./usr/sbin/getcfg.afa

NO_STAGE=	yes
post-extract:
	@${MV} ${WRKDIR}/usr/sbin/afacli.bin ${WRKDIR}/usr/sbin/afacli

.include <bsd.port.mk>
