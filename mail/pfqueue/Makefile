# New ports collection makefile for:	pfqueue
# Date created:				13 Jan 2004
# Whom:					Marcus Grando <marcus@corp.grupos.com.br>
#
# $FreeBSD$
#

PORTNAME=		pfqueue
PORTVERSION=		0.4.2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A console-based tool for handling Postfix 1, Postfix 2 and Exim queues

USE_REINPLACE=		yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		CPPFLAGS="${PTHREAD_CFLAGS}"

MAN1=			pfqueue.1
PLIST_FILES=		bin/pfqueue
.for backend in exim postfix1 postfix2
.  for ext in so so.0
PLIST_FILES+=		lib/libpfq_${backend}.${ext}
.  endfor
.endfor

post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g; s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
