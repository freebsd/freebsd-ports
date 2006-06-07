# New ports collection makefile for:	videogen
# Date created:			Mar 30, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	videogen
PORTVERSION=	0.32
CATEGORIES=	sysutils
MASTER_SITES=	http://www.dynaweb.hu/opensource/videogen/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for calculating XFree86 modelines

MAN1=		videogen.1
PLIST_FILES=	bin/videogen

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS = -Wall -O -g|CFLAGS += -Wall| ; \
		s|CC =|CC ?=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|0.31|${PORTVERSION}|' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/videogen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/videogen.1x ${MAN1PREFIX}/man/man1/videogen.1

.include <bsd.port.mk>
