# New ports collection makefile for:	gtkdiff
# Date created:				17 November 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkdiff
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A frontend program for diff(1) written for GNOME

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtkdiff.1 gtkdiff-rcs.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
