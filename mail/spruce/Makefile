# New ports collection makefile for:	spruce
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spruce
PORTVERSION=	0.6.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erich@tacni.net
COMMENT=	A simple GTK based email client

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

MAN1=		spruce.1

.include <bsd.port.mk>
