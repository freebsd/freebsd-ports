PORTNAME=	tsduck
DISTVERSIONPREFIX=	v
DISTVERSION=	3.43
DISTVERSIONSUFFIX=	-4549
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	thierry@lelegard.fr
COMMENT=	Reference framework for MPEG transport streams
WWW=		https://tsduck.io

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		bootstrap-openjdk11>0:java/bootstrap-openjdk11 \
		coreutils>0:sysutils/coreutils \
		dos2unix:converters/unix2dos \
		doxygen>0:devel/doxygen \
		gnugrep>0:textproc/gnugrep \
		graphviz>0:graphics/graphviz \
		gsed:textproc/gsed \
		gtar:archivers/gtar \
		gtar>0:archivers/gtar \
		qpdf>0:print/qpdf \
		rubygem-asciidoctor-pdf>0:textproc/rubygem-asciidoctor-pdf \
		rubygem-asciidoctor>0:textproc/rubygem-asciidoctor \
		rubygem-rouge>0:textproc/rubygem-rouge \
		str>0:devel/str \
		zip:archivers/zip

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicui18n.so:devel/icu \
		libpcsclite.so:devel/pcsc-lite \
		librist.so:multimedia/librist \
		libsrt.so:www/srt

USES=		dos2unix gmake libedit python shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tsduck

MAKE_ENV=	CXXFLAGS_EXTRA="-isystem ${LOCALBASE}/include" \
		GPROF= \
		LDFLAGS_EXTRA="-L${LOCALBASE}/lib -licuuc" \
		SYSROOT=${STAGEDIR}
ALL_TARGET=	default
TEST_TARGET=	test
BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	docs-html
.endif

.include <bsd.port.mk>
