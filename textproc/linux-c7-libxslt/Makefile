PORTNAME=	libxslt
PORTVERSION=	1.1.28
DISTVERSIONSUFFIX=	-6.el7
PORTREVISION=	1
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XSLT C library for GNOME (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUX=	libxml2
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR:H}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
