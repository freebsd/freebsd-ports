# New ports collection makefile for:	lavaps
# Date created:		11-Oct-99
# Whom:			johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	lavaps
PORTVERSION=	2.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lava lamp of currently running processes

WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		lavaps.1
 
TCL_VER?=	8.4

CPPFLAGS=	-I${LOCALBASE}/include/tcl${TCL_VER} \
		-I${LOCALBASE}/include/tk${TCL_VER} \
		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
PKGNAMESUFFIX=	-gtk2
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	NLS=""
.else
LIB_DEPENDS+=	tk${TCL_VER:S/.//}:${PORTSDIR}/x11-toolkits/tk${TCL_VER:S/.//}
CONFIGURE_ARGS+=	--with-tcltk --disable-nls \
			--with-tcl-ver=${TCL_VER} --with-tk-ver=${TCL_VER}
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
