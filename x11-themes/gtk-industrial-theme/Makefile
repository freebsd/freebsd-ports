# New ports collection makefile for:	gtk-industrial-theme
# Date created:		2 August 2003
# Whom:			Frank Ruell
#
# $FreeBSD$
#

PORTNAME=	gtk-industrial-theme
PORTVERSION=	0.2.26
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.ximian.com/pub/xd2/redhat-9-i386/source/
DISTNAME=	ximian-artwork-${PORTVERSION}-${XIMIAN_SUBVERSION}.ximian.${XIMIAN_DISTVERSION}.src
EXTRACT_SUFX=   .rpm

MAINTAINER=	stoerte@dreamwarrior.net
COMMENT=	Slick theme for GTK1 and GTK2 from Ximian

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

WRKSRC=		${WRKDIR}/ximian-artwork-${PORTVERSION}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_REINPLACE=	yes
USE_LIBTOOL=	yes

XIMIAN_SUBVERSION=	0
XIMIAN_DISTVERSION=	6.1
THEMES_SUBDIRS= ${WRKSRC}/gtk/gtk1-engine/

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
THEMES_SUBDIRS+=	${WRKSRC}/gtk/gtk2-engine/
GTK_VERSION=	2.2.0
PLIST_SUB+=	GTK2="" GTKVERSION=${GTK_VERSION}
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
	@if ! (cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | cpio -i ximian-artwork-${PORTVERSION}.tar.gz 2>/dev/null && ${GZIP_CMD} -dc ximian-artwork-${PORTVERSION}.tar.gz | tar -xf - && ${RM} ximian-artwork-${PORTVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	${CP} ${FILESDIR}/Makefile-gtk1 ${WRKSRC}/gtk/gtk1-engine/Makefile
	${CP} ${FILESDIR}/Makefile-gtk2 ${WRKSRC}/gtk/gtk2-engine/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/gtk/gtk1-engine/Makefile
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/gtk/gtk2-engine/Makefile

do-configure:
	@${DO_NADA}

do-build:
	@for theme_dir in ${THEMES_SUBDIRS};do \
		(cd $$theme_dir; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}); \
	done

do-install:
	@${MKDIR} ${PREFIX}/share/themes/Industrial && ${CHMOD} a+rx ${PREFIX}/share/themes/Industrial
.if defined(WITH_GTK2)
	@${MKDIR} ${PREFIX}/lib/gtk-2.0/${GTK_VERSION}/engines && ${CHMOD} a+rx ${PREFIX}/lib/gtk-2.0/${GTK_VERSION}/engines
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk/gtk2-engine/.libs/libindustrial.so ${PREFIX}/lib/gtk-2.0/${GTK_VERSION}/engines
	@${MKDIR} ${PREFIX}/share/themes/Industrial/gtk-2.0 && ${CHMOD} a+rx ${PREFIX}/share/themes/Industrial/gtk-2.0
	@${INSTALL_DATA} ${WRKSRC}/gtk/gtk2-engine/gtk-2.0/gtkrc ${PREFIX}/share/themes/Industrial/gtk-2.0
	@${INSTALL_DATA} ${WRKSRC}/gtk/gtk2-engine/gtk-2.0/*.png ${PREFIX}/share/themes/Industrial/gtk-2.0
.endif
	@${MKDIR} ${PREFIX}/lib/gtk/themes/engines && ${CHMOD} a+rx ${PREFIX}/lib/gtk/themes/engines
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk/gtk1-engine/.libs/libindustrial.so ${PREFIX}/lib/gtk/themes/engines
	@${MKDIR} ${PREFIX}/share/themes/Industrial/gtk && ${CHMOD} a+rx ${PREFIX}/share/themes/Industrial/gtk
	@${INSTALL_DATA} ${WRKSRC}/gtk/gtk1-engine/gtk/gtkrc ${PREFIX}/share/themes/Industrial/gtk

.include <bsd.port.mk>
