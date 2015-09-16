# Created by: Matt Harris <mattdharris@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	libpwstor
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	SF/kageki/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password storage library for C programmers

USES=		tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CFLAGS+=	-fPIC -DPIC
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pwtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpwstor.so

.include <bsd.port.post.mk>
