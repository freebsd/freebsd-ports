PORTNAME=	vmaf
PORTVERSION=	2.3.0
DISTVERSIONSUFFIX=	-2.el9
MASTER_SITES=	EPEL9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Perceptual video quality assessment based on multi-method fusion (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/Netflix/vmaf

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_FILE=	${WRKSRC}/usr/share/licenses/libvmaf/LICENSE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86-64 are supported

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

#BIN_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL}
LIB_DISTNAMES=	lib${PORTNAME}-${DISTVERSIONFULL}
SRC_DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
#DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/usr/share/doc/lib${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
