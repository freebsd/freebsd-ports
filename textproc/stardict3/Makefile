# New ports collection makefile for:   stardict3
# Date created:        23 July 2008
# Whom:                eric
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DIST_SUBDIR=	stardict

MAINTAINER=	d9364104@mail.nchu.edu.tw
COMMENT=	A cross-platform and international dictionary written in Gtk2

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		enchant.1:${PORTSDIR}/textproc/enchant

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-festival \
		--disable-gucharmap \
		--disable-espeak
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix
USE_GETTEXT=	yes

OPTIONS=	GNOMEUI "GNOME support" On

CONFLICTS=	stardict-2.[0-9]*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNOMEUI)
USE_GNOME+=	libgnomeui
GCONF_SCHEMAS=	stardict.schemas
INSTALLS_OMF=	yes
PLIST_SUB=	GNOME=""
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--disable-gnome-support --disable-schemas-install
PLIST_SUB=	GNOME="@comment not installed: "
.endif

MAN1=		stardict.1

.if (${OSVERSION} < 700109)
EXTRA_PATCHES+=	${FILESDIR}/src_conf.h
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
