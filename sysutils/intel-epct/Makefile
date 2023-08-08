PORTNAME=	epct
PORTVERSION=	1.39.32.5
CATEGORIES=	sysutils net
MASTER_SITES=	https://downloadmirror.intel.com/772094/
PKGNAMEPREFIX=	intel-
DISTFILES=	FreeBSDx64.zip \
		FreeBSD32.zip

MAINTAINER=	freebsd@intel.com
COMMENT=	Intel(R) Ethernet Port Configuration Tool
WWW=		https://www.intel.com/content/www/us/en/download/19438/ethernet-port-configuration-tool-freebsd.html

LICENSE=	IPL
LICENSE_NAME=	Intel Proprietary License
LICENSE_FILE=	${WRKSRC}/${ARCH:S/amd64/FreeBSDx64/:S/i386/FreeBSD32/}/license.pdf
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64 and i386

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	sbin/epct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ARCH:S/amd64/FreeBSDx64/:S/i386/FreeBSD32/}/epct* ${STAGEDIR}${PREFIX}/sbin/epct

.include <bsd.port.mk>
