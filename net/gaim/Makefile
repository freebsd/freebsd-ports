# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaim
PORTVERSION=	0.59.7
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	marcus@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gtk12
WANT_GNOME=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		gaim.1

GNOME_PANEL2=	${X11BASE}/libdata/pkgconfig/libpanelapplet-2.0.pc

.if !defined(WITHOUT_GDK_PIXBUF)
# Note, gdk-pixbuf is needed for buddy icon support.
USE_GNOME+=	gdkpixbuf
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibpanel}!= "" && !exists(${GNOME_PANEL2})
USE_GNOME+=	libpanel
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=	--enable-panel
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	PANEL:="" NOPANEL:="@comment "
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	PANEL:="@comment " NOPANEL:=""
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lpthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
