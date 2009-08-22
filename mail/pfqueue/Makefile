# New ports collection makefile for:	pfqueue
# Date created:				13 Jan 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pfqueue
PORTVERSION=	0.5.6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A console-based tool for handling Postfix 1, Postfix 2 and Exim queues

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

MAN1=		pfqueue.1
MAN5=		pfqueue.conf.5

post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g" \
		-e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|PFQ_SONAME "0.0.0"|PFQ_SONAME "0"|' \
		${WRKSRC}/libpfq/pfqlib.c

.include <bsd.port.mk>
