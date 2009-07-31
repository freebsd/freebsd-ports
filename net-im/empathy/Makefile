# New ports collection makefile for:	empathy
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/net-im/empathy/Makefile,v 1.3 2009/04/15 11:41:56 kwm Exp $

PORTNAME=	empathy
PORTVERSION=	2.26.2
PORTREVISION=	1
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	missioncontrol-server.1:${PORTSDIR}/net-im/telepathy-mission-control \
    		aspell.16:${PORTSDIR}/textproc/aspell \
		telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-farsight.0:${PORTSDIR}/net-im/telepathy-farsight \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver gnomehack gnomeprefix pygtk2 ltverhack \
		gnomepanel
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	GNOME_Megaphone_Applet.schemas empathy.schemas

MAN1=		empathy.1

OPTIONS=	JABBER	"Enable jabber (XMPP) client support" on \
		MSN	"Enable MSN client support" on \
		IRC	"Enable IRC client support" on \
		SALUT	"Enable link-local (serverless) XMPP support" off \
		HAZE	"Enable libpurple protocol integration" off

.include <bsd.port.pre.mk>

.if defined(WITH_JABBER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if defined(WITH_MSN)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-butterfly:${PORTSDIR}/net-im/telepathy-butterfly
.endif

.if defined(WITH_IRC)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if !defined(WITHOUT_SALUT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.if !defined(WITHOUT_HAZE)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|g ; \
		s|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
