# ex:ts=8
# Ports collection Makefile for:	euler
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	euler
PORTVERSION=	1.60.4
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	euler

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A program computes with real and complex numbers and matrices

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WRKSRC=		${WRKDIR}/${DISTNAME:R}/source
MAKEFILE=	makefile
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g ; \
		s,gtk-config,${GTK_CONFIG},g ; \
		s,glib-config,${GLIB_CONFIG},g" ${WRKSRC}/${MAKEFILE}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/euler

.include <bsd.port.mk>
