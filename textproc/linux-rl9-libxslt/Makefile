PORTNAME=	libxslt
PORTVERSION=	1.1.34
DISTVERSIONSUFFIX=	-13.el9_6
PORTREVISION=	3
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XSLT C library for GNOME (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gitlab.gnome.org/GNOME/libxslt/

USES=		cpe linux:rl9
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUX=	libxml2
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
