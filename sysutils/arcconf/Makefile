# Created by: michael@fuckner.net

PORTNAME=	arcconf
DISTVERSION=	3_07_23971
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
LIB_DEPENDS=	libstdc++.so.6:lang/gcc${GCC_DEFAULT}

USES=		zip
USE_GCC=	yes

SUB_FILES+=	${PERIODICSCRIPT}

PERIODICSCRIPT=	410.status-aac-raid

DIST_TYPE=	12_x64
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libncurses.so.8:misc/compat12x

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/periodic/daily/410.status-aac-raid \
		sbin/arcconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_TYPE}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
