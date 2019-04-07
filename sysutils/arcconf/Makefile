# Created by: michael@fuckner.net
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	3_00_23488
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	arcconf_v${DISTVERSION}

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI/SAS RAID administration tool

ONLY_FOR_ARCHS=	amd64

USES=		zip

PERIODICSCRIPT=	410.status-aac-raid

SUB_FILES+=	${PERIODICSCRIPT}

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	May not be redistributed in binary form

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		installs incompatible binaries for FreeBSD
.else
DIST_OSVER=	11
.endif

DIST_EXT=	_x64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_OSVER}${DIST_EXT}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
