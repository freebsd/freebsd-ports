# New ports collection makefile for:	pfqueue
# Date created:				13 Jan 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		pfqueue
PORTVERSION=		0.5.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		mnag@FreeBSD.org
COMMENT=		A console-based tool for handling Postfix 1, Postfix 2 and Exim queues

USE_REINPLACE=		yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		CPPFLAGS="${PTHREAD_CFLAGS}"

MAN1=			pfqueue.1

post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g; s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
