# New ports collection makefile for:	gtkdiff
# Date created:				17 November 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkdiff
PORTVERSION=	1.8.0
PORTREVISION=	8
CATEGORIES=	textproc gnome
MASTER_SITES=	TUCOWS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A frontend for diff(1)

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	gnomehack gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtkdiff.1 gtkdiff-rcs.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
