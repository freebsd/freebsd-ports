# Created by: Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${MAJOR_VERSION}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${MAJOR_VERSION}.x/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libmythes-1.2.so:textproc/mythes

MAJOR_VERSION=	2.2
MINOR_VERSION=	2

USES=		desktop-file-utils execinfo gmake iconv pkgconfig perl5 \
		python:2 tar:xz
USE_QT5=	core concurrent gui svg widgets buildtools_build qmake_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		--enable-qt5 \
		--with-qt-dir=${LOCALBASE}/lib/qt5 \
		${ICONV_CONFIGURE_ARG} \
		--with-extra-prefix=${LOCALBASE}

CPPFLAGS+=	${EXECINFO_CPPFLAGS}
LDFLAGS+=	${EXECINFO_LDFLAGS}
LIBS+=		-lexecinfo

OPTIONS_DEFINE=		ASPELL ENCHANT HUNSPELL NLS
OPTIONS_DEFAULT=	HUNSPELL
OPTIONS_SUB=		yes
ENCHANT_DESC=		Spell checking using Enchant

ASPELL_CONFIGURE_OFF=	--without-aspell
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ENCHANT_CONFIGURE_OFF=	--without-enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
HUNSPELL_CONFIGURE_OFF=	--without-hunspell
HUNSPELL_LIB_DEPENDS=	libhunspell-1.3.so:textproc/hunspell
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1000000 && ${OSVERSION} < 1002000)
EXTRA_PATCHES=		${FILESDIR}/extrapatch-src_frontends_qt4_GuiWorkArea.cpp
.endif

.include <bsd.port.post.mk>
