# oiho a

PORTNAME=	libraqm
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	print

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that encapsulates complex text layout logic

LICENSE=	MIT

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2

USES=		autoreconf:build gmake libtool pkgconfig python:test

USE_GITHUB=	yes
GH_ACCOUNT=	HOST-Oman

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS
DOCS_CONFIGURE_ENABLE=	gtk-doc
DOCS_CONFIGURE_ON=	--with-html-dir=${DOCSDIR}

pre-configure:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|'	\
		${WRKSRC}/tests/Makefile.am
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
