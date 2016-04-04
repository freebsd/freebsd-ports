# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	morebalance
PORTVERSION=	0.4
PORTREVISION=	14
CATEGORIES=	net
MASTER_SITES=	http://morebalance.coolprojects.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular open source user-space load balancing system

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libgnutls.so:security/gnutls \
		libggz.so:games/libggz

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USES=		gettext

LDFLAGS+=	-lz -lpthread
LDFLAGS+=	-L${LOCALBASE}/lib -lpcre -lggz -lgnutls -lintl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5
	${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} install-messages ${MAKE_ARGS}

.include <bsd.port.mk>
