PORTNAME=	arcconf
DISTVERSION=	5.09.00.${BUILD}
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.microchip.com/en-us/adaptec/
DISTNAME=	arcconf_B${BUILD}

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Adaptec SCSI/SAS RAID administration tool
WWW=		https://www.microchip.com/en-us/adaptec/

LICENSE=	Microchip
LICENSE_NAME=	Microchip License
LICENSE_FILE=	${WRKSRC}/freebsd${DIST_TYPE}/cmdline/License.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	precompiled binary
LIB_DEPENDS=	libstdc++.so.6:lang/gcc${GCC_DEFAULT}

USES=		zip
USE_GCC=	yes
BUILD=		28391

NO_BUILD=	yes

SUB_FILES+=	${PERIODICSCRIPT}

PERIODICSCRIPT=	410.status-aac-raid

NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/periodic/daily/410.status-aac-raid \
		sbin/arcconf

.include <bsd.port.pre.mk>

DIST_TYPE=	15_x86_64
.if ${OSVERSION} < 1500000
DIST_TYPE=	14_x86_64
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be redistributed because of licensing reasons. Please visit ${WWW}, accept the Microchip software license agreement, and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_TYPE}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
