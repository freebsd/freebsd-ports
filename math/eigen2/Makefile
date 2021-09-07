# Created by: arved

PORTNAME=	eigen
PORTVERSION=	2.0.17
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/eigen/eigen/get/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

DEPRECATED=	No longer available upstream, no consumers in ports
EXPIRATION_DATE=2021-12-07

USES=		cmake tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-b23437e61a07

post-patch:
	@${REINPLACE_CMD} -e 's|share/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
