PORTNAME=	libksba
PORTVERSION=	1.5.1
DISTVERSIONSUFFIX=	-7.el9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Crypto library based on code used in GnuPG (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnupg.org/software/libgcrypt/index.html

LICENSE=	LGPL21+

USES=		cpe linux:rl9
CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes
USE_LINUX=	libgpg-error
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
