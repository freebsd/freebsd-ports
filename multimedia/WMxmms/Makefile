# New ports collection makefile for:	WMxmms
# Date created:				10 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	WMxmms
PORTVERSION=	0.1.4
CATEGORIES=	multimedia windowmaker
MASTER_SITES=	http://www.dockapps.com/download.php/id/252/ \
		ftp://ftp.nsu.ru/tmp/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	A dockable XMMS interface

BROKEN=		Does not link

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's/^LIBS =/LIBS = ${PTHREAD_LIBS}/'\
		${WRKSRC}/src/Makefile
	@${FIND} ${WRKSRC}/src -name \*.o -delete

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
