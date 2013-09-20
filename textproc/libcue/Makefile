# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	libcue
PORTVERSION=	1.4.0
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	CUE Sheet Parser Library

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext

NO_STAGE=	yes
post-extract:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/libcue/Makefile.in

.include <bsd.port.mk>
