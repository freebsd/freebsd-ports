# New ports collection makefile for:	lavaps
# Date created:		11-Oct-99
# Whom:			johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	lavaps
PORTVERSION=	2.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lava lamp of currently running processes

OPTIONS=	GTK2 "Use GTK2 instead of TCL/TK for GUI (untested!)" off

TCL_VER?=	8.4
.ifdef WITH_GTK2
LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext	\
		iconv:${PORTSDIR}/converters/libiconv
USE_GNOME=	gtk2
CONFIGURE_ARGS+=--with-gtk
PLIST_SUB+=	MO=''

post-configure:
	${MV} ${WRKSRC}/po/Makefile.in ${WRKSRC}/po/Makefile
.else
LIB_DEPENDS+=	tk${TCL_VER:S/.//}:${PORTSDIR}/x11-toolkits/tk${TCL_VER:S/.//}
CONFIGURE_ARGS+=--with-tcltk
USE_REINPLACE=	yes
PLIST_SUB+=	MO='@comment '

post-configure:
	${REINPLACE_CMD} -e 's/ po / /' ${WRKSRC}/Makefile
.endif

USE_PERL5_BUILD=yes, for documentation

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" USE_NLS=yes
CONFIGURE_ENV+=	TK_DOTTED_HI_VERS=${TCL_VER} TCL_DOTTED_HI_VERS=${TCL_VER}
CONFIGURE_ARGS+=--with-tcl-ver=${TCL_VER} --with-tk-ver=${TCL_VER}
CONFIGURE_ARGS+=--with-libintl --with-libiconv
MAN1=		lavaps.1

.include <bsd.port.post.mk>
