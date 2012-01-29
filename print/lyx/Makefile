# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${MAJOR_VERSION}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.chg.ru/pub/X11/lyx/stable/${MAJOR_VERSION}.x/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LICENSE=	GPLv2

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs \
		mythes-1.2.0:${PORTSDIR}/textproc/mythes

CONFLICTS=	lyx-1.[0-9]*
MAJOR_VERSION=	2.0
MINOR_VERSION=	2

USE_XZ=		yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build uic_build rcc_build
USE_GNOME=	desktopfileutils
USE_PYTHON=	yes
USE_PERL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-extra-prefix=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

MAN1=		lyx.1 lyxclient.1 tex2lyx.1

OPTIONS=	ASPELL	 "Use Aspell for spell checking" off \
		ENCHANT  "Use Enchant for spell checking" off \
		HUNSPELL "Use Hunspell for spell checking" on \
		NLS	 "Native language support"	on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=	--without-aspell
.endif

.if !defined(WITHOUT_ENCHANT)
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
.else
CONFIGURE_ARGS+=	--without-enchant
.endif

.if !defined(WITHOUT_HUNSPELL)
LIB_DEPENDS+=	hunspell-1.3.0:${PORTSDIR}/textproc/hunspell
.else
CONFIGURE_ARGS+=	--without-hunspell
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
# Manually install the 48x48 icon and .desktop file.
# Will not be needed in the 2.1 series, see LyX tickets 2820 and 7919.
	${MKDIR} ${LOCALBASE}/share/icons/hicolor/48x48/apps
	${MKDIR} ${LOCALBASE}/share/applications
	${INSTALL_DATA} ${WRKSRC}/lib/images/lyx.png ${LOCALBASE}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${FILESDIR}/lyx.desktop ${LOCALBASE}/share/applications
	${LOCALBASE}/bin/update-desktop-database --quiet

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
