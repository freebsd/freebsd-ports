PORTNAME=	nettle
PORTVERSION=	3.10.1
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Low-level cryptographic library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.lysator.liu.se/~nisse/nettle/

USES=		cpe linux:rl9
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
