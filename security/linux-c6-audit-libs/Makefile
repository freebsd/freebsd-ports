# $FreeBSD$

PORTNAME=	audit
PORTVERSION=	2.4.5
DISTVERSIONSUFFIX=	-6.el6
CATEGORIES=	security linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Dynamic libraries needed for applications to use the Linux audit framework

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
