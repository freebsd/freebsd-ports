PORTNAME=	openssl-devel
PORTVERSION=	1.0.2k
DISTVERSIONSUFFIX=	-26.el7_9
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL headers (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.openssl.org/

LICENSE=	OpenSSL

USES=		cpe linux:c7
USE_LINUX=	openssl
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	openssl-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

DESCR=		${.CURDIR}/../openssl/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
