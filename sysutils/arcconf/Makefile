# Created by: michael@fuckner.net
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	3_01_23531
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	arcconf_v${DISTVERSION}

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI/SAS RAID administration tool

LICENSE=	Microsemi
LICENSE_NAME=	Microsemi License
LICENSE_FILE=	${WRKSRC}/freebsd${DIST_TYPE}/cmdline/License.txt
LICENSE_PERMS=	no-pkg-sell no-dist-sell no-dist-mirror auto-accept

ONLY_FOR_ARCHS=	amd64
USES=		zip
LIB_DEPENDS=	libstdc++.so.6:lang/gcc${GCC_DEFAULT}
USE_GCC=	yes

PERIODICSCRIPT=	410.status-aac-raid

SUB_FILES+=	${PERIODICSCRIPT}

.include <bsd.port.pre.mk>
DIST_TYPE=	11_x64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/periodic/daily/410.status-aac-raid \
		sbin/arcconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_TYPE}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
