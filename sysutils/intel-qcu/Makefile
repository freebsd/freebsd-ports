# Created by: Sergey Kozlov <sergey.kozlov@intel.com>
# $FreeBSD$

PORTNAME=	qcu
PORTVERSION=	1.2
CATEGORIES=	sysutils net
MASTER_SITES=	https://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/ \
		http://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	25852/eng
PKGNAMEPREFIX=	intel-

MAINTAINER=	freebsd@intel.com
COMMENT=	Intel(R) QSFP+ Configuration Utility

LICENSE=	IPL
LICENSE_NAME=	Intel Proprietary License
LICENSE_FILE=	${WRKDIR}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip dos2unix

DOS2UNIX_WRKSRC=	${WRKDIR}
DOS2UNIX_FILES=		license.txt
NO_BUILD=		yes
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

PLIST_FILES=	sbin/qcu

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1001000
IGNORE=		is not supported on FreeBSD 10.0 and older
.endif

.if ${OSVERSION} >= 1100000
BROKEN=		core dump on application startup
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/qcu64e ${STAGEDIR}${PREFIX}/sbin/qcu

.include <bsd.port.post.mk>
