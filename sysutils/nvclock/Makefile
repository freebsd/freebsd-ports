# New ports collection makefile for:	nvclock
# Date created:				August 4, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	nvclock
DISTVERSION=	0.8b2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.linuxhardware.org/nvclock/ \
		http://www.kerneled.com/freebsd/ports/
DISTNAME=	nvclock${DISTVERSION}

MAINTAINER=	sbahra@gwu.edu
COMMENT=	The nVidia graphic card status and overclocking tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

.if defined(WITHOUT_GUI)
PLIST_SUB+=	GTK="@comment "
CONFIGURE_ARGS+="--enable-gtk=no"
.else
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK=""
.endif

MAN1=		nvclock.1

PORTDOCS=	ABOUT AUTHORS ChangeLog FAQ README

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

do-install:
	@${GMAKE} -C ${WRKSRC}/src install
	@${GMAKE} -C ${WRKSRC} install-man
.if !defined(WITHOUT_GUI)
	@${GMAKE} -C ${WRKSRC}/src/gtk install
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${GMAKE} -C ${WRKSRC} install-docs
.endif

.include <bsd.port.mk>
