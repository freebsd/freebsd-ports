# New ports collection Makefile for:	morebalance
# Date created:				Wed Oct 8
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	morebalance
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://mindx.dyndns.org/morebalance/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	A modular open source user-space load balancing system

USE_REINPLACE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_GETOPT_LONG=	yes

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CFLAGS+=	-DUSE_PCRE
LDFLAGS+=	-L${LOCALBASE}/lib -lpcre
.endif

.if defined(WITH_TLS)
LIB_DEPENDS+=	gnutls.7:${PORTSDIR}/security/gnutls \
		ggz.1:${PORTSDIR}/games/libggz
CFLAGS+=	-DUSE_TLS
LDFLAGS+=	-lggz -lgnutls -L${LOCALBASE}/lib
.endif

MAN1=		morebalance.1
MAN5=		morebalance.conf.5

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.conf.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
