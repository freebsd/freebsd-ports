# Created by: bsam
# $FreeBSD$

PORTNAME=	scim-libs
PORTVERSION=	1.4.7
PORTREVISION=	3
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Smart Common Input Method libraries (Linux Fedora 10)

CONFLICTS=	linux-scim-libs-[0-9]* linux-f8-scim-libs-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	gtk2

RPMVERSION=	35.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	scim-${PORTVERSION}-${RPMVERSION}.src.rpm:SOURCE

DESCR=		${.CURDIR}/../scim/pkg-descr

.include <bsd.port.mk>
