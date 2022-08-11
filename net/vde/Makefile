PORTNAME=	vde
PORTVERSION=	1.5.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	vde2

MAKE_ARGS=	CC="${CC}"
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
USES=		cpe gmake tar:tgz
CPE_VENDOR=	${PORTNAME}_project

CFLAGS+=	-fPIC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvdetap.so

.include <bsd.port.mk>
