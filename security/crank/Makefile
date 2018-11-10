# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crank
PORTVERSION=	0.2.1
PORTREVISION=	10
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CRyptANalysis toolKit

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LIB_DEPENDS=	libguile.so:lang/guile

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
GUILE_CONFIG=	${LOCALBASE}/bin/guile-config
LDFLAGS+=	`${GUILE_CONFIG} link`
CFLAGS+=	`${GUILE_CONFIG} compile`

INFO=		crank

.include <bsd.port.mk>
