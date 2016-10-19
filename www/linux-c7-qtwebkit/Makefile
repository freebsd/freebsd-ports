# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qtwebkit
PORTVERSION=	2.3.4
CATEGORIES=	www linux
MASTER_SITES=	EPEL7/q

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QtWebkit (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-qt47-webkit-[0-9]*

ONLY_FOR_ARCHS=	amd64
RPMVERSION=	6.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png xorglibs sqlite3 qt qt-x11
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../webkit-gtk3/pkg-descr # contains no GTK references, reuse

.include <bsd.port.mk>
