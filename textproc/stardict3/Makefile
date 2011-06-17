# New ports collection makefile for:   stardict3
# Date created:        23 July 2008
# Whom:                eric
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DIST_SUBDIR=	stardict

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A cross-platform and international dictionary written in Gtk2

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		enchant.1:${PORTSDIR}/textproc/enchant
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-festival \
		--disable-gucharmap \
		--disable-espeak \
		--disable-updateinfo
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_GETTEXT=	yes

OPTIONS=	GNOME "GNOME support" Off

CONFLICTS_RUN=	stardict-2.[0-9]*

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GNOME)
USE_GNOME+=	gnomeprefix gnomedocutils libgnomeui
GCONF_SCHEMAS=	stardict.schemas
INSTALLS_OMF=	yes
PLIST_SUB=	GNOME=""
.else
USE_AUTOTOOLS=	autoconf
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--disable-gnome-support --disable-schemas-install
PLIST_SUB=	GNOME="@comment "
.endif

MAN1=		stardict.1

post-patch:
.if defined(WITHOUT_GNOME)
	${REINPLACE_CMD} -e '/DATADIRNAME=lib/s,lib,share,' ${WRKSRC}/m4/intltool.m4
	${REINPLACE_CMD} -e '/^SUBDIRS/s,help,,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e '/^GNOME_DOC_INIT/d' ${WRKSRC}/configure.ac
.endif
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		-e 's,firefox,xdg-open,' \
		${WRKSRC}/src/conf.cpp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
