PORTNAME=	libraqm
DISTVERSION=	0.8.0
CATEGORIES=	print
MASTER_SITES=	https://github.com/HOST-Oman/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	raqm-${DISTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that encapsulates complex text layout logic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2

USES=		meson pkgconfig python:3.7+,test tar:xz

USE_LDCONFIG=	yes

TEST_TARGET=	test

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
