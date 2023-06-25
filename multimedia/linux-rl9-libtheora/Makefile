PORTNAME=	libtheora
PORTVERSION=	1.1.1
DISTVERSIONSUFFIX=	-31.el9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Theora Video Compression Codec (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.theora.org/

LICENSE=	BSD3CLAUSE

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
