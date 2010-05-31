# New ports collection Makefile for:	morebalance
# Date created:				Wed Oct 8
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	morebalance
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://morebalance.coolprojects.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modular open source user-space load balancing system

LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre \
		gnutls.40:${PORTSDIR}/security/gnutls \
		ggz.5:${PORTSDIR}/games/libggz

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GETTEXT=	YES

LDFLAGS+=	-L${LOCALBASE}/lib -lpcre -lggz -lgnutls \
		-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		morebalance.1
MAN5=		morebalance.conf.5

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.conf.5 ${MANPREFIX}/man/man5
	@${MAKE_ENV} ${MAKE} -C ${WRKSRC} install-messages

.include <bsd.port.mk>
