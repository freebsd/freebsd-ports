PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.3
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${MAJOR_VERSION}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${MAJOR_VERSION}.x/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)
WWW=		https://www.lyx.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmythes-1.2.so:textproc/mythes

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}
qt5_PKGNAMESUFFIX=	-qt5

.if ${FLAVOR} == qt5
DEPRECATED=		Depends on unsupported Qt 5
EXPIRATION_DATE=	2026-12-31
.endif

CONFLICTS_INSTALL=	lyx lyx-qt5

MAJOR_VERSION=	2.5

USES=		autoreconf compiler:c++11-lang desktop-file-utils gmake iconv \
		pkgconfig perl5 python:build qt:${FLAVOR:S/qt//} shebangfix \
		tar:xz xorg
_USE_QT_qt5=	core concurrent gui svg widgets x11extras buildtools:build \
		qmake:build
_USE_QT_qt6=	base svg
USE_QT=		${_USE_QT_${FLAVOR}}
USE_XORG=	xcb
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--${FLAVOR:S/qt5/disable/:S/qt6/enable/}-qt6 \
		--without-included-mythes \
		--with-qt-dir=${LOCALBASE}/lib/${FLAVOR} \
		${ICONV_CONFIGURE_ARG} \
		--with-extra-prefix=${LOCALBASE}
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions	\
		--exclude '3rdparty/[!n]*'	\
		--exclude cygwin	\
		--exclude MacOSX	\
		--exclude Win32
SHEBANG_FILES=	lib/configure.py \
		lib/lyx2lyx/lyx2lyx \
		lib/scripts/lyxpaperview.py \
		lib/scripts/listerrors \
		lib/scripts/gnuplot2pdf.py \
		lib/scripts/spreadsheet_to_docbook.py \
		lib/scripts/svg2pdftex.py \
		lib/scripts/svg2pstex.py

LDFLAGS+=	-Wl,--as-needed
LIBS+=		-lexecinfo

TEST_TARGET=	check

OPTIONS_DEFINE=		ASPELL ENCHANT HUNSPELL NLS
OPTIONS_DEFAULT=	HUNSPELL
OPTIONS_SUB=		yes
ENCHANT_DESC=		Spell checking using Enchant

ASPELL_CONFIGURE_OFF=	--without-aspell
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ENCHANT_CONFIGURE_OFF=	--without-enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
HUNSPELL_CONFIGURE_OFF=	--without-hunspell
HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext
NLS_VARS_OFF=		AUTORECONF_ARGS+=--exclude=autopoint

post-patch:
	@${GREP} -rl "python -tt" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' 's|python -tt|${PYTHON_CMD} -tt|'

post-stage:
	${RM} /usr/local/lib/python3.11/site-packages/_distutils_hack/__pycache__/__init__.cpython-311.opt-2.pyc

.include <bsd.port.mk>
