PORTNAME=	libxml2
PORTVERSION=	2.9.13
DISTVERSIONSUFFIX=	-6.el9_4
PORTREVISION=	3
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://xmlsoft.org/

LICENSE=	MIT

USES=		cpe linux:rl9
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
