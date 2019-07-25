# Created by: michael@fuckner.net
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	3_01_23531
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	arcconf_v${DISTVERSION}

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI/SAS RAID administration tool

ONLY_FOR_ARCHS=	amd64
LIB_DEPENDS=	libstdc++.so.6:lang/gcc${GCC_DEFAULT}

USES=		zip

PERIODICSCRIPT=	410.status-aac-raid

SUB_FILES+=	${PERIODICSCRIPT}

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	May not be redistributed in binary form

.include <bsd.port.pre.mk>
DIST_TYPE=	11_x64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_TYPE}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
