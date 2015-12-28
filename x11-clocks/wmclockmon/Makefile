# Created by: pat
# $FreeBSD$

PORTNAME=	wmclockmon
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Digital clock dockapp with a similar look to wmcpuload

USE_XORG=	xpm
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/wmclockmon-config/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in 1 2
	@${INSTALL_DATA} ${WRKSRC}/doc/sample${i}.wmclockmonrc ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
