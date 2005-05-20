# New ports collection makefile for:	pfqueue
# Date created:				13 Jan 2004
# Whom:					Marcus Grando <marcus@corp.grupos.com.br>
#
# $FreeBSD$
#

PORTNAME=		pfqueue
PORTVERSION=		0.3.8
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A console-based tool for handling postfix queues

USE_REINPLACE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}

MAN1=			pfqueue.1
PLIST_FILES=		bin/pfqueue

post-patch:
	${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g; s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
