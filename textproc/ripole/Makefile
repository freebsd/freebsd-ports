# New ports collection makefile for:	ripole
# Date created:				June 21, 2005
# Whom:					Freddie Cash <fcash@sd73.bc.ca>
#
# $FreeBSD$

PORTNAME=	ripole
PORTVERSION=	0.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.pldaniels.com/ripole/

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A small program designed to pull attachments out of OLE2 documents

ALL_TARGET=	default

PLIST_FILES=	bin/ripole

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
