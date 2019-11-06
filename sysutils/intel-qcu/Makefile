# Created by: Sergey Kozlov <sergey.kozlov@intel.com>
# $FreeBSD$

PORTNAME=	qcu
PORTVERSION=	2.30.23.0
CATEGORIES=	sysutils net
MASTER_SITES=	https://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/ \
		http://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	25852/eng
PKGNAMEPREFIX=	intel-
DISTNAME=	FreeBSDx64

MAINTAINER=	freebsd@intel.com
COMMENT=	Intel(R) QSFP+ Configuration Utility

BROKEN=		unfetchable

LICENSE=	IPL
LICENSE_NAME=	Intel Proprietary License
LICENSE_FILE=	${WRKSRC}/Intel_Proprietary_License.pdf
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

USES=		zip

NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_ARCH=		yes
NO_ARCH_IGNORE=		qcu

PLIST_FILES=	sbin/qcu

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcu64e ${STAGEDIR}${PREFIX}/sbin/qcu

.include <bsd.port.post.mk>
