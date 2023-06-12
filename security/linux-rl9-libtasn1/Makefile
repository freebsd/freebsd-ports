PORTNAME=	libtasn1
PORTVERSION=	4.16.0
DISTVERSIONSUFFIX=	-8.el9_1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ASN.1 structure parser library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/software/libtasn1/

LICENSE=	LGPL21+

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CPE_VENDOR=	gnu

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
