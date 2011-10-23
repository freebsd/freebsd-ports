# New ports collection makefile for:   stardict3
# Date created:        23 July 2008
# Whom:                eric
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	3.0.3
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
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
CONFIGURE_WRKSRC=	${WRKSRC}/dict
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

PROJECTHOST=	stardict-3

OPTIONS=	GNOME "GNOME support" On

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
MAKE_ARGS+=     AUTOMAKE="${TRUE}" ACLOCAL="${TRUE}"
.endif

MAN1=		stardict.1

post-patch:
.if defined(WITHOUT_GNOME)
	${REINPLACE_CMD} -e '/DATADIRNAME=lib/s,lib,share,' ${WRKSRC}/dict/m4/intltool.m4
	${REINPLACE_CMD} -e '/^SUBDIRS/s,help,,' ${WRKSRC}/dict/Makefile.in
	${REINPLACE_CMD} -e '/^GNOME_DOC_INIT/d' \
		-e '/^help\/Makefile/d' ${WRKSRC}/dict/configure.ac
.endif
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/dict/src/conf.cpp

pre-configure:
	cd ${WRKSRC}/lib && \
	${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
