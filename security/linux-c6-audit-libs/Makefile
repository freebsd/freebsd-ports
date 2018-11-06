# $FreeBSD$

PORTNAME=	audit-libs
PORTVERSION=	2.4.5
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Dynamic libraries needed for applications to use the Linux audit framework

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
RPMVERSION=	6.el6
SRC_DISTFILES=	audit-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
