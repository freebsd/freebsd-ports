# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	4.10
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ASN.1 structure parser library (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		cpe linux:c7
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
