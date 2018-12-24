# Created by: Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}
DISTVERSIONSUFFIX=	-2
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${MAJOR_VERSION}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${MAJOR_VERSION}.x/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libmythes-1.2.so:textproc/mythes

WRKSRC=		${WRKDIR}/${DISTNAME:S,${DISTVERSIONSUFFIX}$$,,}

MAJOR_VERSION=	2.3
MINOR_VERSION=	1

USES=		compiler:c++11-lang desktop-file-utils gmake iconv pkgconfig \
		perl5 python:2.7 qt:5 shebangfix tar:xz
USE_QT=		core concurrent gui svg widgets buildtools_build qmake_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		--enable-qt5 \
		--with-qt-dir=${LOCALBASE}/lib/qt5 \
		${ICONV_CONFIGURE_ARG} \
		--with-extra-prefix=${LOCALBASE}
SHEBANG_FILES=	lib/configure.py \
		lib/lyx2lyx/lyx2lyx \
		lib/scripts/listerrors \
		lib/scripts/gnuplot2pdf.py \
		lib/scripts/svg2pdftex.py \
		lib/scripts/svg2pstex.py

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
HUNSPELL_LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

.include <bsd.port.mk>
