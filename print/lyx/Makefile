# Created by: Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}
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
MINOR_VERSION=	5

USE_XZ=		yes
USE_GMAKE=	yes
USE_QT4=	corelib gui moc_build uic_build rcc_build
USE_GNOME=	desktopfileutils
USE_PYTHON=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-extra-prefix=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

MAN1=		lyx.1 lyxclient.1 tex2lyx.1

OPTIONS_DEFINE=		ASPELL ENCHANT HUNSPELL NLS
OPTIONS_DEFAULT=	HUNSPELL NLS
ENCHANT_DESC=		Spell checking using Enchant
HUNSPELL_DESC=		Spell checking using Hunspell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=	--without-aspell
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
.else
CONFIGURE_ARGS+=	--without-enchant
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell-1.3.0:${PORTSDIR}/textproc/hunspell
.else
CONFIGURE_ARGS+=	--without-hunspell
.endif

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
# Manually install the 48x48 icon and .desktop file.
# Will not be needed in the 2.1 series, see LyX tickets 2820 and 7919.
	${MKDIR} ${PREFIX}/share/icons/hicolor/48x48/apps
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/lib/images/lyx.png ${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${FILESDIR}/lyx.desktop ${PREFIX}/share/applications
	${LOCALBASE}/bin/update-desktop-database --quiet

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
