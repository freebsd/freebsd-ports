# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flowcanvas
PORTVERSION=	0.7.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Gtkmm/Gnomecanvasmm widget

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libgvc.so:graphics/graphviz \
		libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26 \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		pkgconfig tar:bzip2 waf
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		"s|$$[{]LIBDIRNAME[}]/pkgconfig|libdata/pkgconfig| ; \
		 s|-fshow-column'|-fshow-column ${CXXFLAGS}'|" \
			${WRKSRC}/autowaf/autowaf.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
