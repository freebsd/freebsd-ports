PORTNAME=	gnutls
PORTVERSION=	3.7.6
PORTREVISION=	2
DISTVERSIONSUFFIX=	-23.el9_3.4
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gnutls.org/

USES=		cpe linux:rl9
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_LINUX=	libidn2 libtasn1 nettle p11-kit
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
