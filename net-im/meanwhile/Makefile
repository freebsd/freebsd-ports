# New ports collection makefile for:	meanwhile
# Date created:		24 June 2004
# Whom:		 	Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meanwhile
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open Source implementation of the Lotus Sametime protocol

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-doxygen=no \
		--with-gmp-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-doc-${PORTVERSION}

.include <bsd.port.mk>
