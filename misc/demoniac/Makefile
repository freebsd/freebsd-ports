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

LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea

USE_MESA=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
