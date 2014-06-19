# Created by: igor@zynaps.ru
# $FreeBSD$

PORTNAME=	trafshow
PORTVERSION=	3.1
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem
PKGNAMESUFFIX=	3
EXTRACT_SUFX=	.tgz

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Full screen visualization of network traffic (an ancient version)

CONFLICTS=	trafshow-[45].*

.if defined(WITH_TRAFSHOW_SLANG) || \
    (exists(${LOCALBASE}/lib/libslang.a) && !defined(WITHOUT_TRAFSHOW_SLANG))
LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
.endif

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
ALL_TARGET=	trafshow

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${STAGEDIR}${PREFIX}/etc/trafshow.dist
	if [ ! -f ${STAGEDIR}${PREFIX}/etc/trafshow ]; then \
		${CP} ${STAGEDIR}${PREFIX}/etc/trafshow.dist ${STAGEDIR}${PREFIX}/etc/trafshow; \
	fi

.include <bsd.port.mk>
