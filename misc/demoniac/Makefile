# ex:ts=8
# Ports collection makefile for:	demoniac
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	demoniac
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.calodox.org/demoniac/files/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A tool for exploring and animating graphics effects

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_REINPLACE=	yes
USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
