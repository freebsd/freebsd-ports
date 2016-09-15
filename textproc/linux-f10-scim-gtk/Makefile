# Created by: bsam
# $FreeBSD$

PORTNAME=	scim-gtk
PORTVERSION=	1.4.7
PORTREVISION=	3
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Smart Common Input Method platform, gtk module, (Linux Fedora 10)

CONFLICTS=	linux-scim-gtk-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	gtk2 scimlibs

RPMVERSION=	35.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	scim-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
