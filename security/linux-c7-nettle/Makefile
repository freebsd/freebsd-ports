PORTNAME=	nettle
PORTVERSION=	2.7.1
DISTVERSIONSUFFIX=	-8.el7
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Low-level cryptographic library (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
