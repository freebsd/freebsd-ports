# Created by: John Heidemann <johnh@isi.edu>
# $FreeBSD$

PORTNAME=	lavaps
PORTVERSION=	2.7
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lava lamp of currently running processes

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_PERL5_BUILD=	yes
USE_XORG=	x11 xext sm ice

MAN1=		lavaps.1

OPTIONS_DEFINE=	GTK
GTK_DESC=	Build with GTK frontend instead of the default TK

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK}
PKGNAMESUFFIX=	-gtk2
USE_GNOME+=	gtk20 libgnomeui
USES+=		gettext
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	NLS=""
.else
USE_TK=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CPPFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
CONFIGURE_ARGS+=	--with-tcltk --disable-nls \
			--with-tcl-ver=${TCL_VER} --with-tk-ver=${TCL_VER}
PLIST_SUB+=	NLS="@comment "
.endif

# Fix a race to allow parallel builds
post-patch:
	@${REINPLACE_CMD} -e '/rm lavaps\.pod/d' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
