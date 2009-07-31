# New ports collection makefile for:	fidelio
# Date created:				13 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fidelio
PORTVERSION=	1.0.b1
PORTREVISION=	6
CATEGORIES=	net-p2p gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME client for Hotline

USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|<xmlversion.h>|<libxml/xmlversion.h>|g' ${WRKSRC}/configure

.include <bsd.port.mk>
