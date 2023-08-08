PORTNAME=	libxml2
PORTVERSION=	2.9.1
DISTVERSIONSUFFIX=	-6.el7_9.6
PORTREVISION=	4
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Linux CentOS ${LINUX_DIST_VER})
WWW=		http://xmlsoft.org/

LICENSE=	MIT

USES=		cpe linux:c7
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
