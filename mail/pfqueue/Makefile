# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pfqueue
PORTVERSION=	0.5.6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console-based tool for handling Postfix 1, Postfix 2, and Exim queues

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}

MAN1=		pfqueue.1
MAN5=		pfqueue.conf.5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g" \
		-e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|PFQ_SONAME "0.0.0"|PFQ_SONAME "0"|' \
		${WRKSRC}/libpfq/pfqlib.c

.include <bsd.port.mk>
