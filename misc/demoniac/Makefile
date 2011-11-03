# ex:ts=8
# Ports collection makefile for:	demoniac
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	demoniac
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.calodox.scene.org/demoniac/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for exploring and animating graphics effects

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2011-12-03

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GL=		yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
PLIST_FILES=	bin/demoniac share/demoniac/pixmaps/logo.xpm
PLIST_DIRS=	share/demoniac/pixmaps share/demoniac

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
