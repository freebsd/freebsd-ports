# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	qalculate
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-gtk/${PORTNAME}-gtk-${PORTVERSION}
DISTNAME=	${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (Gnome frontend)

LICENSE=	GPLv2

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot \
		wget:ftp/wget

USES=		gettext gmake
USE_GNOME=	intltool libglade2 libgnome
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=\(.*\)|=${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/qalculate-gtk.desktop.in
	@${REINPLACE_CMD} -e \
		's/^GMSGFMT = @GMSGFMT@/GMSGFMT = msgfmt/' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
