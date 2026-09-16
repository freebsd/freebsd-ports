PORTNAME=	ufs-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	8.14.12
CATEGORIES=	sysutils

MAINTAINER=	jaeyoon@FreeBSD.org
COMMENT=	Tool for UFS (Universal Flash Storage) devices
WWW=		https://github.com/SanDisk-Open-Source/ufs-utils

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	SanDisk-Open-Source

# The upstream Makefile has no "all" or "install" target.
ALL_TARGET=	ufs-utils
PLIST_FILES=	bin/ufs-utils

# Base installs this header only when it has the ufshci(4) passthrough
# ioctl, so the check works on main and stable branches alike.
.if !exists(/usr/include/dev/ufshci/ufshci_ioctl.h)
IGNORE=	needs the ufshci(4) passthrough ioctl, which this system lacks
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufs-utils ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
