# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	1.2
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ARGS+=	F_CONF=${PREFIX}/etc/pound.cfg

MAN8=	pound.8

.include <bsd.port.mk>
