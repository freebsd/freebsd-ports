# New ports collection makefile for:	mutella
# Date created:				2/12/2001
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	mutella
PORTVERSION=	0.4.5
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gavin.atkinson@ury.york.ac.uk
COMMENT=	A command line Gnutella client

MAN1=		mutella.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
