# New ports collection makefile for:	trickle
# Date created:				04.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	trickle
PORTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight, portable bandwidth shaper

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-libevent=${LOCALBASE} \
		--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		trickle.1
MAN5=		trickled.conf.5
MAN8=		trickled.8

post-install:
	if [ ! -f ${PREFIX}/etc/trickled.conf ]; then \
		${INSTALL_DATA} ${FILESDIR}/trickled.conf ${PREFIX}/etc/trickled.conf; \
		${INSTALL_DATA} ${FILESDIR}/trickled.conf ${PREFIX}/etc/trickled.conf.default; \
	else \
		${INSTALL_DATA} ${FILESDIR}/trickled.conf ${PREFIX}/etc/trickled.conf.default; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
