PORTNAME=	apertium
PORTVERSION=	3.8.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems
WWW=		https://www.apertium.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12_powerpc64=	fails to configure on powerpc64 elfv1: *** unable to locate pcrecpp library ***

BUILD_DEPENDS=	bash:shells/bash \
		utf8cpp3>0:devel/utf8cpp3
LIB_DEPENDS=	libicudata.so:devel/icu \
		liblttoolbox.so:textproc/lttoolbox \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake gnome libtool localbase:ldflags pathfix \
		pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	apertium:contrib
GH_PROJECT=	apertium-get:contrib
GH_SUBDIR=	apertium/apertium-get:contrib
GH_TAGNAME=	74d7d35:contrib
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

SHEBANG_FILES=	apertium/apertium-get/apertium-get.sh scripts/apertium-editdist \
		scripts/apertium-filter-dix.in scripts/apertium-filter-rules.in \
		scripts/apertium-filter-xml scripts/apertium-genvdix \
		scripts/apertium-genvldix scripts/apertium-genvrdix \
		scripts/apertium-metalrx scripts/apertium-metalrx-to-lrx.in \
		scripts/apertium-translate-to-default-equivalent.in

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include/utf8cpp

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/apertium/perceptron_spec.h
.endif

.include <bsd.port.mk>
