# New ports collection makefile for:	lavaps
# Date created:		11-Oct-99
# Whom:			johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	lavaps
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A lava lamp of currently running processes

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	-x-includes="${X11BASE}/include" -x-libraries="${X11BASE}/lib"
USE_PERL5_BUILD=	yes

MAN1=		lavaps.1

TCL_VER?=	8.4

CPPFLAGS+=	-I${LOCALBASE}/include/tcl${TCL_VER} \
		-I${LOCALBASE}/include/tk${TCL_VER} \
		-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include/tcl${TCL_VER} \
		-I${LOCALBASE}/include/tk${TCL_VER} \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	GTK	"Build with GTK frontend instead of the default TK" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK)
PKGNAMESUFFIX=	-gtk2
USE_GNOME+=	gtk20
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	NLS=""
.else
LIB_DEPENDS+=	tk${TCL_VER:S/.//}:${PORTSDIR}/x11-toolkits/tk${TCL_VER:S/.//}
CONFIGURE_ARGS+=	--with-tcltk --disable-nls \
			--with-tcl-ver=${TCL_VER} --with-tk-ver=${TCL_VER}
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
