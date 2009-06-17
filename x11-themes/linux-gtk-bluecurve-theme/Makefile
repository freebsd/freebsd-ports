# New ports collection makefile for:	linux-gtk-bluecurve-theme
# Date created:			19 Jun 2004
# Whom:				Jean-Yves lefort
#
# $FreeBSD$
#

PORTNAME=	gtk-bluecurve-theme
DISTVERSION=	0.117-1
CATEGORIES=	x11-themes linux
DISTNAME=	redhat-artwork-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bluecurve GTK+ 1.x and 2.x themes (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
PLIST=		${WRKDIR}/.plist

# GTK+ 1.x theme engine
GTK1_RCDIR=	gtk
GTK1_ENGINEDIR=	usr/lib/gtk/themes/engines
GTK1_ENGINEDIRS=${GTK1_ENGINEDIR} usr/lib/gtk/themes usr/lib/gtk

# GTK+ 2.x theme engine
GTK2_RCDIR=	gtk-2.0
GTK2_ENGINEDIR=	usr/lib/gtk-2.0/2.4.0/engines
GTK2_ENGINEDIRS=${GTK2_ENGINEDIR} usr/lib/gtk-2.0/2.4.0 usr/lib/gtk-2.0

EXTRA_STYLES=	BerriesAndCream Gnome Grape Lime Slate Strawberry Tangerine
THEMES=		Bluecurve ${EXTRA_STYLES:S|^|Bluecurve-|}

pre-install:
	@${RM} -f ${PLIST}
.for v in 1 2
	@${ECHO_CMD} '${GTK${v}_ENGINEDIR}/libbluecurve.so' >> ${PLIST}
.  for d in ${GTK${v}_ENGINEDIRS}
	@${ECHO_CMD} '@dirrmtry ${d}' >> ${PLIST}
.  endfor
.  for t in ${THEMES}
	@${ECHO_CMD} 'usr/share/themes/${t}/${GTK${v}_RCDIR}/gtkrc' >> ${PLIST}
	@${ECHO_CMD} '@dirrm usr/share/themes/${t}/${GTK${v}_RCDIR}' >> ${PLIST}
.  endfor
.endfor
.for t in ${THEMES}
	@${ECHO_CMD} '@dirrm usr/share/themes/${t}' >> ${PLIST}
.endfor
	@${ECHO_CMD} '@dirrmtry usr/share/themes' >> ${PLIST}

do-install:
.for v in 1 2
	${MKDIR} ${PREFIX}/${GTK${v}_ENGINEDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${GTK${v}_ENGINEDIR}/libbluecurve.so ${PREFIX}/${GTK${v}_ENGINEDIR}
.  for t in ${THEMES}
	${MKDIR} ${PREFIX}/usr/share/themes/${t}/${GTK${v}_RCDIR}
	${INSTALL_DATA} ${WRKSRC}/usr/share/themes/${t}/${GTK${v}_RCDIR}/gtkrc ${PREFIX}/usr/share/themes/${t}/${GTK${v}_RCDIR}
.  endfor
.endfor

.include <bsd.port.mk>
