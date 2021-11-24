# Created by: Matt Harris <mattdharris@users.sourceforge.net>

PORTNAME=	libpwstor
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	SF/kageki/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password storage library for C programmers

DEPRECATED=	Abandonware, last release in 2008
EXPIRATION_DATE=2022-03-31

USES=		ssl tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CFLAGS+=	-fPIC -DPIC

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pwtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpwstor.so

.include <bsd.port.post.mk>
