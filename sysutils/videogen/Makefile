# New ports collection makefile for:	videogen
# Date created:			Mar 30, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	videogen
PORTVERSION=	0.21
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://paranoia.rulez.org/videogen/download/
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	markp@FreeBSD.org

MAN1=		videogen.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -lm -o videogen videogen.c && \
		${GZIP_CMD} < ${WRKSRC}/videogen.1x > ${WRKSRC}/videogen.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/videogen ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/some_modes.sh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/videogen.1.gz ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
