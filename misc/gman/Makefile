# ex:ts=8
# New ports collection makefile for:	gman
# Date created:			Mar 30, 3001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gman
PORTVERSION=	0.9.3
CATEGORIES=	misc
MASTER_SITES=	http://homex.coolconnect.com/user/xkwang/gman/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview

USE_GNOMENG=	yes
USE_GNOME=	gtk12

MAN1=	gman.1x

post-patch:
	@${PERL} -pi -e "s,^CXX =,#CXX =,g ; s,^CXXFLAGS =,CXXFLAGS+=,g ; \
		s,gtk-config,${GTK_CONFIG},g ; s,= /usr,= ${PREFIX},g ; \
		s,/var/www,${LOCALBASE}/www,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
