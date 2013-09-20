# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crank
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CRyptANalysis toolKit

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
GUILE_CONFIG=	${LOCALBASE}/bin/guile-config
LDFLAGS+=	`${GUILE_CONFIG} link`
CFLAGS+=	`${GUILE_CONFIG} compile`
USE_GMAKE=	yes

INFO=		crank

NO_STAGE=	yes
.include <bsd.port.mk>
