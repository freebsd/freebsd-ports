# New ports collection makefile for:	trafshow
# Date created:         25 September 1996
# Whom:                 igor@zynaps.ru
#
# $FreeBSD$
#

PORTNAME=	trafshow
PORTVERSION=	5.2.3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Full screen visualization of network traffic

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	trafshow

MAN1=		trafshow.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PKGMESSAGE=	${PKGDIR}/pkg-message.nodevfs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/colormask.c ${WRKSRC}/trafshow.1 ${WRKSRC}/trafshow.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${PREFIX}/etc/trafshow.dist
	if [ ! -e ${PREFIX}/etc/trafshow ]; then \
		${CP} -p ${PREFIX}/etc/trafshow.dist ${PREFIX}/etc/trafshow; \
	fi
.if ${OSVERSION} < 500000
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
