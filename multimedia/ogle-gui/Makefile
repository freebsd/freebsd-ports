# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.9.2
PORTREVISION=	15
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}_gui-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	An add-on graphical user interface for Ogle

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.11:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	glade-2.0:${PORTSDIR}/devel/libglade2 \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_GETTEXT=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		gtk20
WANT_GNOME=	yes
USE_XORG=	xpm
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-dvd-includes=${LOCALBASE}/include \
		--with-dvdcontrol=${LOCALBASE} \
		--without-included-gettext \
		--enable-gtk2 \
		--with-gtk-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-xml-prefix=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!=""
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
.endif

PLIST_SUB=	SHARE_DATADIR="${SHARE_DATADIR}"

post-patch:
# fix library version
	@${REINPLACE_CMD} -E -e "s|(libglade\.so)\.0|\1.4|; \
		s|%%LOCALBASE%%|${LOCALBASE}|" \
			${CONFIGURE_WRKSRC}/configure
# correct path for program data files
	@${REINPLACE_CMD} -E -e \
		's!(CONFIG_FILE[[:space:]]*=[^"]+\")[^/]+/!\1${LOCALBASE}/share/!; \
		s!(CONFIG_FILE_DTD[[:space:]]*=[^"]+\")[^/]+/!\1${LOCALBASE}/share/!' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
