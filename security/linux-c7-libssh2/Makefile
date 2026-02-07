PORTNAME=	libssh2
PORTVERSION=	1.8.0
DISTVERSIONSUFFIX=	-4.el7_9.1
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.libssh2.org/

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
