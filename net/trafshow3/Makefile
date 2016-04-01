# Created by: igor@zynaps.ru
# $FreeBSD$

PORTNAME=	trafshow
PORTVERSION=	3.1
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/sem
PKGNAMESUFFIX=	3

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Full screen visualization of network traffic (an ancient version)

CONFLICTS=	trafshow-[45].*

.if defined(WITH_TRAFSHOW_SLANG) || \
    (exists(${LOCALBASE}/lib/libslang.a) && !defined(WITHOUT_TRAFSHOW_SLANG))
LIB_DEPENDS=	libslang.so:devel/libslang2
.endif

USES=		tar:tgz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
ALL_TARGET=	trafshow

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${STAGEDIR}${PREFIX}/etc/trafshow.sample

.include <bsd.port.mk>
