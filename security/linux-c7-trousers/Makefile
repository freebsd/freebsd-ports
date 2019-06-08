# $FreeBSD$

PORTNAME=	trousers
PORTVERSION=	0.3.14
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Open-source TCG Software Stack (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	openssl
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
