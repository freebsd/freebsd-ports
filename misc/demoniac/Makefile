# ex:ts=8
# Ports collection makefile for:	demoniac
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	demoniac
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.calodox.org/demoniac/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for exploring and animating graphics effects

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GL=		yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
PLIST_FILES=	bin/demoniac share/demoniac/pixmaps/logo.xpm
PLIST_DIRS=	share/demoniac/pixmaps share/demoniac

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
