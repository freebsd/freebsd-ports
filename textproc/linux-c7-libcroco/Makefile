PORTNAME=	libcroco
PORTVERSION=	0.6.12
DISTVERSIONSUFFIX=	-6.el7_9
PORTREVISION=	1
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	CSS2 parsing library (CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

USES=		cpe linux:c7
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUX=	libxml2
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
