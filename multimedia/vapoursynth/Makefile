PORTNAME=	vapoursynth
DISTVERSION=	R66
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video processing framework with simplicity in mind
WWW=		https://www.vapoursynth.com/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
LIB_DEPENDS=	libzimg.so:graphics/sekrit-twc-zimg

USES=		autoreconf compiler:c++17-lang gmake libtool localbase pathfix python pkgconfig
USE_PYTHON=	cython
USE_GITHUB=	yes
USE_LDCONFIG=	yes

BINARY_ALIAS=	cython=cython-${PYTHON_VER}
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/lib/vapoursynth

CONFIGURE_ARGS=	--disable-static

OPTIONS_DEFINE=	DEBUG DOCS FRAME_GUARD
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=		debug

DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx \
				${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_PORTDOCS=			*

FRAME_GUARD_DESC=		Check integrity after each filter
FRAME_GUARD_CONFIGURE_ENABLE=	guard-pattern

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && defined(MACHINE_CPU) && ${MACHINE_CPU:Mavx2}
CONFIGURE_ARGS+= --enable-x86-asm
.else
CONFIGURE_ARGS+= --disable-x86-asm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		-e '/AC_SEARCH.*libiconv/d' \
		-e '/test/s/[^ ]*libiconv.*-a //' \
		${WRKSRC}/configure.ac

post-build-DOCS-on:
	@${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} ${WRKSRC}/doc ${WRKSRC}/doc/_build/html	

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
