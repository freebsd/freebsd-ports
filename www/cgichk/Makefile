# New ports collection makefile for:	cgichk
# Date created:			Jun 8, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	cgichk
PORTVERSION=	2.60
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	markp@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	cgichk
USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} -e "s/^(CC|CFLAGS).+//g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		"s@/etc/@${PREFIX}/etc/@g; s/#include <getopt.h>//g; \
		s@^(?=.+sys/socket.h)@#include <sys/types.h>\n@g;" \
		${WRKSRC}/cgichk.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgichk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cgichk.cfg ${PREFIX}/etc/cgichk.cfg.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
