PORTNAME=	libgcrypt
PORTVERSION=	1.10.0
DISTVERSIONSUFFIX=	-10.el9_2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Crypto library based on code used in GnuPG (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnupg.org/software/libgcrypt/index.html

LICENSE=	LGPL21+

USES=		cpe linux:rl9
CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes
USE_LINUX=	libgpg-error
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
