# New ports collection makefile for:	safecat
# Date created:		27 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	safecat
PORTVERSION=	1.12
CATEGORIES=	sysutils mail
MASTER_SITES=	http://budney.homeunix.net:8080/users/budney/linux/software/safecat/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Safely write data to a directory using D. J. Bernstein's Maildir ideology

USE_REINPLACE=	yes

MAN1=		safecat.1 maildir.1

do-configure:
		${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/conf-root
		${REINPLACE_CMD} -e "s,cc -O2,${CC} ${CFLAGS}," ${WRKSRC}/conf-cc
		${REINPLACE_CMD} -e "s,cc -s,${CC} ${CFLAGS} ${STRIP}," ${WRKSRC}/conf-ld

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.include <bsd.port.mk>
