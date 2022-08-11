PORTNAME=	trafshow
PORTVERSION=	3.1
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/sem
PKGNAMESUFFIX=	3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full screen visualization of network traffic (an ancient version)

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
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${STAGEDIR}${PREFIX}/bin/trafshow3
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${STAGEDIR}${PREFIX}/man/man1/trafshow3.1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${STAGEDIR}${PREFIX}/etc/trafshow3.sample

.include <bsd.port.mk>
