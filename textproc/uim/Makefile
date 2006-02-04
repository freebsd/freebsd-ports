# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://uim.freedesktop.org/releases/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Input method library

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget glib20
USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:15

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFIGURE_ARGS=	--enable-emacs
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib  -L${LOCALBASE}/lib"

OPTIONS=	GTK "Enable GTK support" off \
		QT "Enable QT support" off \
		GNOME "Enable GNOME support" off \
		ANTHY "Enable Anthy support" off \
		CANNA "Enable Canna support" off \
		M17NLIB "Enable m17lib support" off \
		PRIME "Enable PRIME support" off \
		SCIM "Enable SCIM support" off \
		SKK "Enable SKK support" off

MAN1=		uim-xim.1
DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim
PLIST_SUB=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_editline.c
.endif

.if ${PERL_LEVEL} >= 500600
USE_PERL5_BUILD=yes
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:${PORTSDIR}/lang/perl5
CONFIGURE_ENV+=	INTLTOOL_PERL="${LOCALBASE}/bin/perl"
.endif

.if defined(WITH_GTK)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--with-gtk2
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=--without-gtk2
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_QT)
LIB_DEPENDS+=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt33
CONFIGURE_ARGS+=--with-qt
CONFIGURE_ENV+=	QTDIR=${X11BASE}/lib QTINCDIR=${X11BASE}/include \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include" LIBS="${LIBS} ${PTHREAD_LIBS} -L${X11BASE}/lib"
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=--without-qt
PLIST_SUB+=	QT="@comment "
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomepanel
CONFIGURE_ARGS+=--with-gnome2 --enable-applet
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=--without-gnome2 --disable-applet
PLIST_SUB+=	GNOME="@comment "
.endif

.if defined(WITH_ANTHY)
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
CONFIGURE_ARGS+=--with-anthy
PLIST_SUB+=	ANTHY=""
.else
CONFIGURE_ARGS+=--without-anthy
PLIST_SUB+=	ANTHY="@comment "
.endif

.if defined(WITH_CANNA)
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
CONFIGURE_ARGS+=--with-canna
PLIST_SUB+=	CANNA=""
.else
CONFIGURE_ARGS+=--without-canna
PLIST_SUB+=	CANNA="@comment "
.endif

.if defined(WITH_M17NLIB)
LIB_DEPENDS+=	m17n.1:${PORTSDIR}/devel/m17n-lib
CONFIGURE_ARGS+=--with-m17nlib
PLIST_SUB+=	M17NLIB=""
.else
CONFIGURE_ARGS+=--without-m17nlib
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if defined(WITH_PRIME)
BUILD_DEPENDS+=	prime:${PORTSDIR}/japanese/prime
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--with-prime
PLIST_SUB+=	PRIME=""
.else
CONFIGURE_ARGS+=--without-prime
PLIST_SUB+=	PRIME="@comment "
.endif

.if defined(WITH_SCIM)
USE_GCC=	3.4
LIB_DEPENDS+=	scim-1.0.9:${PORTSDIR}/textproc/scim
CONFIGURE_ARGS+=--with-scim
PLIST_SUB+=	SCIM=""
.else
CONFIGURE_ARGS+=--without-scim
PLIST_SUB+=	SCIM="@comment "
.endif

.if defined(WITH_SKK)
RUN_DEPENDS+=	${LOCALBASE}/share/skk/SKK-JISYO.L:${PORTSDIR}/japanese/skk-jisyo
.endif

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/scm/skk-custom.scm

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DOCSDIR}/KEY
	${INSTALL_DATA} ${WRKSRC}/fep/README ${DOCSDIR}/README.fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${DOCSDIR_JA}/README.fep
	${INSTALL_DATA} ${WRKSRC}/xim/README ${DOCSDIR}/README.xim
.endif

.include <bsd.port.post.mk>
