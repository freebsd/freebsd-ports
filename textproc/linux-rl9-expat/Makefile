PORTNAME=	expat
PORTVERSION=	2.5.0
DISTVERSIONSUFFIX=	-5.el9_6
PORTREVISION=	7
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML 1.0 parser written in C (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/libexpat/libexpat

LICENSE=	MIT

USES=		cpe linux:rl9
CPE_VENDOR=	${CPE_PRODUCT}_project
CPE_PRODUCT=	lib${PORTNAME}
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}2/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
