# New ports collection makefile for:	udpcast
# Date created:		Mon Jul 19 19:10:56 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udpcast
PORTVERSION=	0.${RELEASE_DATE}
CATEGORIES=	mbone sysutils
MASTER_SITES=	http://udpcast.linux.lu/current/
DISTNAME=	${PORTNAME}-${RELEASE_DATE}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A file transfer tool using ethernet's multicast

USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

RELEASE_DATE=	20040531

PROGRAM_SBIN_FILES=	udp-receiver udp-sender

PLIST_FILES=	sbin/udp-receiver \
		sbin/udp-sender
PORTDOCS=	Changelog.txt cmd.html

MAN1=		udp-receiver.1 udp-sender.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/libbb_udpcast.h

do-configure:
# C{C,FLAGS}, PTHREAD_* safeness
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|^(CFLAGS[[:space:]]*=.+)$$|\1 ${CFLAGS} ${CPPFLAGS} ${PTHREAD_CFLAGS}|' \
		-e 's|^(LDFLAGS[[:space:]]*=.+)$$|\1 ${LDFLAGS}|' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
.ifndef(NOPORTDOCS)
. for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif
.for file in ${PROGRAM_SBIN_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin/
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${MANPREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
