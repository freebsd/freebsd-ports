# New ports collection makefile for:	nvclock
# Date created:				August 4, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	nvclock
DISTVERSION=	0.8b4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nvclock
DISTNAME=	nvclock${DISTVERSION}

MAINTAINER=	sbahra@gwu.edu
COMMENT=	The nVidia graphic card status and overclocking tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	aclocal:19 autoheader:262 autoconf:262

PLIST_FILES=	bin/nvclock \
		bin/smartdimmer

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=--enable-gtk=no --enable-qt=no --enable-nvcontrol=no
.else
USE_XORG=	xext
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/nvclock_gtk
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
	@${REINPLACE_CMD} -e 's|$$(DISTDIR)||' ${WRKSRC}/src/Makefile.in

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
