# New ports collection makefile for:   vlog
# Date created:                31 March 2002
# Whom:                        hannes sowa <satbran@web.de>
#
# $FreeBSD$
#

PORTNAME=	vlog
PORTVERSION=	1.1f
CATEGORIES=	security
MASTER_SITES=	http://inc2.com/download/
DISTNAME=	vlog-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	satbran@web.de

ALL_TARGET=	it
MAKE_ARGS=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS} -lcurses"
WRKSRC=		${WRKDIR}/vlog
USE_REINPLACE=	yes

MAN1=		vlog.1
MANCOMPRESSED=	no

post-patch:
	${REINPLACE_CMD} -e "s@/usr/local@${PREFIX}@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
