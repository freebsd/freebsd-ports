# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qtwebkit
PORTVERSION=	2.3.4
DISTVERSIONSUFFIX=	-6.el7
PORTREVISION=	2
CATEGORIES=	www linux
MASTER_SITES=	EPEL7/q

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Qt WebKit implementation (Linux CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	amd64

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png xorglibs sqlite3 qt qt-x11
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-qt47-webkit-[0-9]*

.include <bsd.port.mk>
