# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.8.5
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.8:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		glade.4:${PORTSDIR}/devel/libglade \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-dvd-includes=${LOCALBASE}/include \
		--with-dvdcontrol=${LOCALBASE} \
		--without-included-gettext \
		--with-gtk-prefix=${X11BASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libglade-config=${X11BASE}/bin/libglade-config \
		--with-xml-prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!=""
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
SHARE_DATADIR=	share/gnome
.else
SHARE_DATADIR=	share
.endif

PLIST_SUB=	SHARE_DATADIR="${SHARE_DATADIR}"

post-patch:
# fix library version
	@${REINPLACE_CMD} -E -e "s|(libglade\.so)\.0|\1.4|; \
		s|%%LOCALBASE%%|${LOCALBASE}|" \
			${CONFIGURE_WRKSRC}/configure
# correct path for program data files
	@${REINPLACE_CMD} -E -e \
		's!(LOCALEDIR[[:space:]]*=[^"]+\")[^/]+/!\1${PREFIX}/share/!; \
		s!(CONFIG_FILE[[:space:]]*=[^"]+\")[^/]+/!\1${LOCALBASE}/share/!; \
		s!(CONFIG_FILE_DTD[[:space:]]*=[^"]+\")[^/]+/!\1${LOCALBASE}/share/!' \
			${WRKSRC}/src/Makefile.in
# install locale correctly
	@${REINPLACE_CMD} -E -e \
		's!(datadir[[:space:]]*=).*$$!\1${PREFIX}/share!' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.post.mk>
