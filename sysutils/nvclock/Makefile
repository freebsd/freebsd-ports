# New ports collection makefile for:	nvclock
# Date created:				August 4, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	nvclock
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.linuxhardware.org/nvclock/ \
		http://www.kerneled.com/freebsd/ports/
DISTNAME=	nvclock${PORTVERSION}

MAINTAINER=	sbahra@kerneled.org
COMMENT=	The nVidia graphic card status and overclocking tool

USE_GMAKE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

.if defined(WITHOUT_GUI)
PLIST_SUB+=	GTK="@comment "
CONFIGURE_ARGS+="--enable-gtk=no"
.else
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK=""
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} "* You can disable nvclock's GTK user interface *"
	@${ECHO_MSG} "* by defining WITHOUT_GUI.                     *"
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} ""

post-patch:
.for i in src/gtk/Makefile.in src/backend/Makefile.in
	@${REINPLACE_CMD} -e 's|"CFLAGS="|"CFLAGS+="|g' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
