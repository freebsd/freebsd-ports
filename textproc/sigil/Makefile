PORTNAME=	sigil
DISTVERSION=	2.6.2
CATEGORIES=	textproc

MAINTAINER=	jonc@chen.org.nz
COMMENT=	WYSIWYG ePub editor
WWW=		https://sigil-ebook.com/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpcre2-16.so:devel/pcre2 \
		libhunspell-1.7.so:textproc/hunspell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=0.15.0:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

USES=		cmake cpe desktop-file-utils gl localbase:ldflags \
		minizip pkgconfig python qt:6 shebangfix
CPE_VENDOR=	${PORTNAME}-ebook
USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	Sigil
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/lib/sigil
USE_QT=		base declarative positioning svg webchannel webengine \
		tools:build imageformats:run

SHEBANG_FILES=	src/Resource_Files/plugin_launchers/python/*.py \
		src/Resource_Files/python3lib/*.py

CMAKE_ARGS=	-DUSE_SYSTEM_LIBS:BOOL=1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sigil/*.so

.include <bsd.port.mk>
