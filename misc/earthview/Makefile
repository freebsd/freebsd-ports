# ex:ts=8
# Ports collection makefile for:	earthview
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	earthview
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_XLIB=	yes
CFLAGS+=	-I${X11BASE}/include
ALL_TARGET=	earthview

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%CC%%|${CC}|g" \
		-e "s|%%CFLAGS%%|${CFLAGS}|g" -e "s|%%X11BASE%%|${X11BASE}|g" \
		${WRKSRC}/Makefile

pre-build:
	@${RM} -f ${WRKSRC}/earthview

.include <bsd.port.mk>
