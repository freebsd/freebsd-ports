# New ports collection makefile for:	trafshow
# Date created:         25 September 1996
# Whom:                 igor@zynaps.ru
#
# $FreeBSD$
#

PORTNAME=	trafshow
PORTVERSION=	4.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sasknow.com/pub/trafshow/ \
		ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryan@sasknow.com
COMMENT=	Full screen visualization of network traffic

CONFLICTS=	trafshow-3.*
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_TRAFSHOW_SLANG) || \
    (exists(${LOCALBASE}/lib/libslang.a) && !defined(WITHOUT_TRAFSHOW_SLANG))
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
.else
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
ALL_TARGET=	trafshow

MAN1=		trafshow.1

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${PREFIX}/etc/trafshow.dist
	${CP} ${PREFIX}/etc/trafshow.dist ${PREFIX}/etc/trafshow

.include <bsd.port.post.mk>
