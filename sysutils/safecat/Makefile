# New ports collection makefile for:	safecat
# Date created:		27 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	safecat
PORTVERSION=	1.9
CATEGORIES=	sysutils mail
MASTER_SITES=	http://www.nb.net/~lbudney/linux/software/safecat/

MAINTAINER=	roam@FreeBSD.org

USE_REINPLACE=	yes

MAN1=		safecat.1 maildir.1

do-configure:
		${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/conf-root
		${REINPLACE_CMD} -e "s,cc -O2,${CC} ${CFLAGS}," ${WRKSRC}/conf-cc
		${REINPLACE_CMD} -e "s,cc -s,${CC} ${CFLAGS} ${STRIP}," ${WRKSRC}/conf-ld

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.include <bsd.port.mk>
