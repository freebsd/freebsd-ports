# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47-webkit
PORTVERSION=	4.7.2
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	https://www.mirrorservice.org/sites/dl.atrpms.net/el6-i386/atrpms/testing/ \
		https://www.mirrorservice.org/sites/dl.atrpms.net/el6-x86_64/atrpms/testing/ \
		LOCAL/xmj
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/atrpms/6

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 6)

ONLY_FOR_ARCHS=	i386 amd64
RPMVERSION=	1_18.el6
USE_LINUX=	c6
USE_LINUX_APPS=	fontconfig png xorglibs sqlite3 qt47 qt47-x11
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=  ${.CURDIR}/../../www/webkit-gtk3/pkg-descr # contains no GTK references, reuse

SRC_DISTFILES:=		# unretrievable

.include <bsd.port.mk>
