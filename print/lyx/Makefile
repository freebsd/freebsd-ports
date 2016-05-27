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

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libmythes-1.2.so:textproc/mythes

MAJOR_VERSION=	2.1
MINOR_VERSION=	4

USES=		desktop-file-utils gmake iconv pkgconfig perl5 python:2 tar:xz
USE_QT4=	corelib gui moc_build uic_build rcc_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		${ICONV_CONFIGURE_ARG} \
		--with-extra-prefix=${LOCALBASE}

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

.include <bsd.port.mk>
