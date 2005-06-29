# New ports collection makefile for:	xlreader
# Date created:				25 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xlreader
PORTVERSION=	0.9.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.giffin.org/download/ \
		http://critical.ch/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Convert .xls spread sheets to tab delimited CSV or SQL inserts

USE_REINPLACE=	yes
PLIST_FILES=	bin/xlreader

post-patch:
	@${REINPLACE_CMD} -e \
		's|-L/usr/local/lib||; s|^CFLAGS=.*||; s|gcc|${CC}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
