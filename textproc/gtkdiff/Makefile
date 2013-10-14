# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkdiff
PORTVERSION=	1.8.0
PORTREVISION=	9
CATEGORIES=	textproc gnome
MASTER_SITES=	TUCOWS

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A frontend for diff(1)

DEPRECATED=	Gnome1 EOLed by upstream for a while.
EXPIRATION_DATE=	2013-11-05

USE_GNOME=	gnomehack gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gtkdiff.1 gtkdiff-rcs.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
