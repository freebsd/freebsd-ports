# Created by: igor@zynaps.ru
# $FreeBSD$

PORTNAME=	trafshow
PORTVERSION=	5.2.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Full screen visualization of network traffic

CONFLICTS=	trafshow-4.* trafshow3-*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	trafshow

MAN1=		trafshow.1

OPTIONS_DEFINE=		IPV6

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/colormask.c ${WRKSRC}/trafshow.1 ${WRKSRC}/trafshow.c
.if ${OSVERSION} >= 800074
	@${PATCH} -d ${WRKSRC} < ${FILESDIR}/extra-patch-800074+
.endif

.if ${PORT_OPTIONS:MIPV6}
CFLAGS+=	-DINET6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${PREFIX}/etc/trafshow.dist
	if [ ! -e ${PREFIX}/etc/trafshow ]; then \
		${CP} -p ${PREFIX}/etc/trafshow.dist ${PREFIX}/etc/trafshow; \
	fi

.include <bsd.port.mk>
