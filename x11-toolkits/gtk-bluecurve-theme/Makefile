# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	gtk-bluecurve-theme
PORTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	9/en/os/i386/SRPMS
DISTFILES=	redhat-artwork-${PORTVERSION}-${RH_SUBVERSION}.src.rpm

MAINTAINER=	rzheka@users.sourceforge.net
COMMENT=	Bluecurve unified-look theme for GTK1 and GTK2 from RedHat 8.0

BUILD_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

WRKSRC= 	${WRKDIR}/redhat-artwork-${PORTVERSION}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_REINPLACE=	yes
USE_LIBTOOL=	yes

RH_SUBVERSION=	1
THEMES_SUBDIRS= ${WRKSRC}/art/gtk/Bluecurve1

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
THEMES_SUBDIRS+=	${WRKSRC}/art/gtk/Bluecurve
PLIST_SUB+=	GTK2="" GTKVERSION="2.2.0"
.else
PLIST_SUB+=	GTK2="@comment "
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "By default only gtk-1.2 theme engine will be built."
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_GTK2=yes   Build gtk-2 theme"
	@${ECHO} ""

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && rpm2cpio.pl ${_DISTDIR}/${DISTFILES} | cpio -i redhat-artwork-${PORTVERSION}.tar.gz 2>/dev/null && ${GZIP_CMD} -dc redhat-artwork-${PORTVERSION}.tar.gz | tar -xf - && ${RM} redhat-artwork-${PORTVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	${CP} ${FILESDIR}/Makefile-gtk1 ${WRKSRC}/art/gtk/Bluecurve1/Makefile
	${CP} ${FILESDIR}/Makefile-gtk2 ${WRKSRC}/art/gtk/Bluecurve/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/art/gtk/Bluecurve1/Makefile
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/art/gtk/Bluecurve/Makefile

do-configure:
	@${DO_NADA}

do-build:
	@for theme_dir in ${THEMES_SUBDIRS};do \
		(cd $$theme_dir; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}); \
	done

do-install:
	@${MKDIR} ${PREFIX}/share/themes/Bluecurve && ${CHMOD} a+rx ${PREFIX}/share/themes/Bluecurve
.if defined(WITH_GTK2)
	@${MKDIR} ${PREFIX}/lib/gtk-2.0/2.2.0/engines && ${CHMOD} a+rx ${PREFIX}/lib/gtk-2.0/2.2.0/engines
	@${MKDIR} ${PREFIX}/share/themes/Bluecurve/gtk-2.0 && ${CHMOD} a+rx ${PREFIX}/share/themes/Bluecurve/gtk-2.0
	@${INSTALL_PROGRAM} ${WRKSRC}/art/gtk/Bluecurve/.libs/libbluecurve.so ${PREFIX}/lib/gtk-2.0/2.2.0/engines
	@${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve/gtk-2.0/gtkrc ${PREFIX}/share/themes/Bluecurve/gtk-2.0
.endif
	@${MKDIR} ${PREFIX}/lib/gtk/themes/engines && ${CHMOD} a+rx ${PREFIX}/lib/gtk/themes/engines
	@${INSTALL_PROGRAM} ${WRKSRC}/art/gtk/Bluecurve1/.libs/libbluecurve.so ${PREFIX}/lib/gtk/themes/engines
	@${MKDIR} ${PREFIX}/share/themes/Bluecurve/gtk && ${CHMOD} a+rx ${PREFIX}/share/themes/Bluecurve/gtk
	@${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve1/gtk/gtkrc ${PREFIX}/share/themes/Bluecurve/gtk

.include <bsd.port.mk>
