# New ports collection makefile for:	spruce
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spruce
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erich@tacni.net

BUILD_DEPENDS=	msgfmt-old:${PORTSDIR}/devel/gettext-old
LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		MSGFMT="${LOCALBASE}/bin/msgfmt-old" \
		XGETTEXT="${LOCALBASE}/bin/xgettext-old"

MAN1=		spruce.1

.include <bsd.port.mk>
