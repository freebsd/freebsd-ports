PORTNAME=	gnutls
PORTVERSION=	3.3.29
DISTVERSIONSUFFIX=	-9.el7_6
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_LINUX=	libtasn1 nettle p11-kit trousers
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
