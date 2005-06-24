# New ports collection makefile for:	ripole
# Date created:				June 21, 2005
# Whom:					Freddie Cash <fcash@sd73.bc.ca>
#
# $FreeBSD$

PORTNAME=	ripole
PORTVERSION=	0.1.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.pldaniels.com/ripole/
#DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A small program designed to pull attachments out of OLE2 documents

CONFLICTS=	ripole-devel-*
LATEST_LINK=	ripole
ALL_TARGET=	default

PLIST_FILES=	bin/ripole

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripole ${PREFIX}/bin/ripole

.include <bsd.port.post.mk>
