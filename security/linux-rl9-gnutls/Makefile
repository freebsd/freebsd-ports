PORTNAME=	gnutls
PORTVERSION=	3.8.3
DISTVERSIONSUFFIX=	-4.el9_4
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
