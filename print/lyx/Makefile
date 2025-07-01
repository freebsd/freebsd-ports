PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.4
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

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libmythes-1.2.so:textproc/mythes

MAJOR_VERSION=	2.4

USES=		autoreconf compiler:c++11-lang desktop-file-utils gmake iconv \
		pkgconfig perl5 python:build qt:5 shebangfix tar:xz xorg
USE_QT=		core concurrent gui svg widgets x11extras buildtools:build qmake:build
USE_XORG=	xcb
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--without-included-boost \
		--without-included-mythes \
		--with-qt-dir=${LOCALBASE}/lib/qt5 \
		${ICONV_CONFIGURE_ARG} \
		--with-extra-prefix=${LOCALBASE}
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions	\
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
HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

post-patch:
	@${GREP} -rl "python -tt" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' 's|python -tt|${PYTHON_CMD} -tt|'

post-stage:
	${RM} /usr/local/lib/python3.11/site-packages/_distutils_hack/__pycache__/__init__.cpython-311.opt-2.pyc

.include <bsd.port.mk>
