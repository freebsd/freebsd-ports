# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	0.9
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		F_CONF=${PREFIX}/etc/pound.cfg

MAN8=	pound.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pound ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/pound.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
