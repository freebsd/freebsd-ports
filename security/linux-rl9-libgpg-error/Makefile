PORTNAME=	libgpg-error
PORTVERSION=	1.42
DISTVERSIONSUFFIX=	-5.el9
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common error values for all GnuPG components (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnupg.org/software/libgpg-error/

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
