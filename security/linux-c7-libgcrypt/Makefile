PORTNAME=	libgcrypt
PORTVERSION=	1.5.3
DISTVERSIONSUFFIX=	-14.el7
PORTREVISION=	4
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Crypto library based on code used in GnuPG (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

USES=		cpe linux:c7
CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes
USE_LINUX=	libgpg-error
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
