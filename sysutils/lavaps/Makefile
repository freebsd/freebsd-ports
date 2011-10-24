# New ports collection makefile for:	lavaps
# Date created:		11-Oct-99
# Whom:			johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	lavaps
PORTVERSION=	2.7
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lava lamp of currently running processes

GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_PERL5_BUILD=	yes
USE_XORG=	x11 xext sm ice

MAN1=		lavaps.1

OPTIONS=	GTK	"Build with GTK frontend instead of the default TK" off

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_GTK)
PKGNAMESUFFIX=	-gtk2
USE_GNOME+=	gtk20 libgnomeui
USE_GETTEXT=	yes
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

.include <bsd.port.post.mk>
