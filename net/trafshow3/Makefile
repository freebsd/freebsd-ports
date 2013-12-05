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
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	trafshow

MAN1=		trafshow.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${PREFIX}/etc/trafshow.dist
	if [ ! -f ${PREFIX}/etc/trafshow ]; then \
		${CP} ${PREFIX}/etc/trafshow.dist ${PREFIX}/etc/trafshow; \
	fi

.include <bsd.port.mk>
