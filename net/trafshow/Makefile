# Created by: igor@zynaps.ru
# $FreeBSD$

PORTNAME=	trafshow
PORTVERSION=	5.2.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.nsk.su/pub/RinetSoftware/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Full screen visualization of network traffic

LICENSE=	BSD2CLAUSE

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
ALL_TARGET=	trafshow

CONFLICTS=	trafshow-4.* trafshow3-*

OPTIONS_DEFINE=	IPV6
IPV6_CFLAGS=	-DINET6

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/colormask.c ${WRKSRC}/trafshow.1 ${WRKSRC}/trafshow.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${STAGEDIR}${PREFIX}/etc/trafshow.dist

.include <bsd.port.mk>
