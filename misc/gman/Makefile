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
MASTER_SITES=	http://stud3.tuwien.ac.at/~e0025974/distfiles/ \
		http://homex.coolconnect.com/user/xkwang/gman/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes

MAN1=	gman.1x

post-patch:
	@${REINPLACE_CMD} -e 's,^CXX =,#CXX =,g' \
		-e 's,^CXXFLAGS =,CXXFLAGS+=,g' \
		-e 's,gtk-config,${GTK_CONFIG},g' \
		-e 's,= /usr,= ${PREFIX},g' \
		-e 's,\-O2,,g' \
		-e 's,\-lgtk \-lgdk \-lpthread ,`${GTK_CONFIG} \-\-libs gthread` ,g' ${WRKSRC}/Makefile 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gman ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${PREFIX}/bin/gman.cgi
	@${MKDIR} ${PREFIX}/www/cgi-bin/gman
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${PREFIX}/www/cgi-bin/gman
	${INSTALL_MAN} ${WRKSRC}/gman.1x ${MANPREFIX}/man/man1

.include <bsd.port.mk>
