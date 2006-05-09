# New ports collection makefile for:   gtk13
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#   $MCom: ports-stable/x11-toolkits/gtk20/Makefile,v 1.8 2006/03/13 22:32:30 mezz Exp $
#

PORTNAME=	gtk
PORTVERSION=	2.8.17
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/gtk+/2.8,} \
		ftp://ftp.gtk.org/pub/gtk/v2.8/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

USE_BZIP2=	yes
LATEST_LINK=	gtk20
PREFIX?=	${X11BASE}

.if !defined(REFERENCE_PORT)

PORTREVISION=	1

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${X11BASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XLIB=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
USE_GNOME=	gnomehack atk pango ltverhack
CONFIGURE_ARGS=	--enable-static --with-xinput=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
GTK_VERSION=	2.4.0
PLIST_SUB=	GTK_VERSION="${GTK_VERSION}"

gdk_pixbuf_MAN=	gdk-pixbuf-query-loaders.1
gtk_MAN=	gtk-query-immodules-2.0.1 gtk-update-icon-cache.1

MAN1=		${gdk_pixbuf_MAN} ${gtk_MAN}

# Setting WITH_DEBUG=yes effectively adds -g to $CFLAGS
# unless doing so would clobber a preexisting $CFLAGS.
# Setting to yes also causes debugging into to be spat out
# on the command-line.
# Set to minimum if you want to send in a backtrace; set
# to yes if you want to know what gtk thinks it's doing.
.if defined(WITH_DEBUG) || defined(WITHOUT_DEBUG)
.if defined(WITHOUT_DEBUG) || ${WITH_DEBUG:L} == "no"
CONFIGURE_ARGS+=	--enable-debug=no
.else
.if ${WITH_DEBUG:L} == "yes"
CONFIGURE_ARGS+=	--enable-debug=yes
STRIP=
.else
CONFIGURE_ARGS+=	--enable-debug=minimum
CFLAGS+=		-g
.endif
STRIP=
.endif
.endif

.include <bsd.port.pre.mk>

# There is a SSE2 bug in either GCC or in our libc, when use p4, p-m or else
# is being use in CPUTYPE that enable SSE2 will causing Java with GTK2 and
# Mono/gtk-sharp crash. Disable SSE2 to solve the crash and see ports/72014
# for detail.
.if ${OSVERSION} >= 500000 && ( ${ARCH} == "i386" || ${ARCH} == "amd64" ) \
	&& ${CC} != "icc"
CFLAGS+=	-mno-sse2
.endif

pre-everything::
.if !defined(WITH_DEBUG)
	@${ECHO_MSG}
	@${ECHO_MSG} "Enable or disable debugging with the following knob"
	@${ECHO_MSG} "WITH_DEBUG=[no|minimum|yes] or WITHOUT_DEBUG=yes"
	@${ECHO_MSG}
	@${ECHO_MSG} "Default is minimum"
	@${ECHO_MSG}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${GREP} -l lgmodule | \
		${XARGS} ${REINPLACE_CMD} -e 's|-lgmodule|@GMODULE_LIBS@|g'
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/gtk/xdgmime/xdgmime.c
# GnomeVFS needs pthread; gtk-demo may use GnomeVFS (via GtkFileChooser)
	@${REINPLACE_CMD} -e 's|@CFLAGS@|& ${PTHREAD_CFLAGS}|; \
		s|@LDFLAGS@|& ${PTHREAD_LIBS}|' \
		${WRKSRC}/demos/gtk-demo/Makefile.in

pre-build:
	@${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	-@${FIND} ${X11BASE}/share/icons -type d -depth 1 -exec \
		${PREFIX}/bin/gtk-update-icon-cache -q -f {} \; 2>/dev/null
	@${MKDIR} ${PREFIX}/lib/gtk-2.0/modules
	@${MKDIR} ${PREFIX}/lib/gtk-2.0/${GTK_VERSION}/engines
	${INSTALL_MAN} ${gdk_pixbuf_MAN:S|^|${WRKSRC}/docs/reference/gdk-pixbuf/|} \
		${PREFIX}/man/man1
	${INSTALL_MAN} ${gtk_MAN:S|^|${WRKSRC}/docs/reference/gtk/|} \
		${PREFIX}/man/man1

.include <bsd.port.post.mk>

.endif
