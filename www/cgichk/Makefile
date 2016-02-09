# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	cgichk
PORTVERSION=	2.60
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://BSDforge.com/projects/source/www/cgichk/

LICENSE=	GPLv2

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Web site vulnerability scanner

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	cgichk

post-patch:
	${REINPLACE_CMD} -e "s/^(CC|CFLAGS).+//g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		"s@/etc/@${PREFIX}/etc/@g; s/#include <getopt.h>//g;" \
		${WRKSRC}/cgichk.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgichk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cgichk.cfg ${STAGEDIR}${PREFIX}/etc/cgichk.cfg.sample

.include <bsd.port.mk>
