# ex:ts=8
# New ports collection makefile for:	Crank
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crank
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CRyptANalysis toolKit

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
GUILE_CONFIG=	${LOCALBASE}/bin/guile-config
CONFIGURE_ENV=	CFLAGS="${CFLAGS} `${GUILE_CONFIG} compile`" \
		LDFLAGS="`${GUILE_CONFIG} link`"
USE_GMAKE=	yes

.include <bsd.port.mk>
