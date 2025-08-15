PORTNAME=	coq
PORTVERSION=	8.20.1
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	math
DISTVERSIONPREFIX=	V
#DISTVERSIONSUFFIX=	.0
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Theorem prover based on lambda-C
WWW=		https://coq.inria.fr/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SA_DIR}/num/META:math/ocaml-num \
		${SA_DIR}/zarith/META:math/ocaml-zarith \
		bash:shells/bash \
		camlp5:devel/ocaml-camlp5
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${SA_DIR}/num/META:math/ocaml-num \
		${SA_DIR}/zarith/META:math/ocaml-zarith

USES=		emacs gettext-runtime gmake gnome ocaml:camlp4,dune,ldconfig python:env shebangfix tex
SHEBANG_FILES=	tools/*.py
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30 gtksourceview3
USE_LDCONFIG=	${PREFIX}/lib/coq
OCAML_LDLIBS=		${OCAML_SITELIBDIR}/coq-core
OCAML_PACKAGES=		coq-core coq-stdlib coq

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-mandir ${PREFIX}/share/man \
		-docdir ${OCAML_DOCSDIR} \
		-bytecode-compiler yes \
		-native-compiler yes

CONFLICTS_INSTALL=	coq coq-emacs_* # bin/coq-tex bin/coq_makefile bin/coqc bin/coqchk bin/coqdep bin/coqdoc bin/coqide bin/coqmktop bin/coqtop bin/coqtop.byte bin/coqwc bin/coqworkmgr bin/gallina

OPTIONS_DEFINE=		DOCS IDE
OPTIONS_DEFAULT=	IDE
OPTIONS_SUB=		yes
IDE_DESC=		Include desktop environment (coqide)
IDE_BUILD_DEPENDS=	${SA_DIR}/lablgtk3/META:x11-toolkits/ocaml-lablgtk3
IDE_RUN_DEPENDS=	${SA_DIR}/lablgtk3/META:x11-toolkits/ocaml-lablgtk3
IDE_VARS=		ocaml_packages+=coqide-server ocaml_packages+=coqide
# IDE_CONFIGURE_OFF=	-coqide no
# XXX needs fixing
# DOCS_USES=		tex python:env
# DOCS_USE=		TEX=latex:build,dvipsk:build
# DOCS_BUILD_DEPENDS=	hevea:textproc/hevea \
# 			sphinx-build:textproc/py-sphinx \
# 			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
# 			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-bibtex>0:textproc/py-sphinxcontrib-bibtex@${PY_FLAVOR}
# DOCS_VARS=		ocaml_packages+=coq-doc
#DOCS_CONFIGURE_OFF=	-with-doc no

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

pre-build:
	@${MAKE_CMD} -C ${WRKSRC} dunestrap

# XXX to keep dune-install happy, until DOCS build gets fixed
post-build:
	@${TOUCH} ${WRKSRC}/${DUNE_BUILD_DIR}/default/coq-doc.install

post-install:
	@(cd ${STAGEDIR}${PREFIX} ; \
		${FIND} ${OCAML_SITELIBDIR} -type f '(' -name '*.cmxs' -o -name '*_stubs.so' ')' ; \
		${FIND} bin -type f -not -name '*.byte' ; \
	) | while read f; \
		do \
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/$$f ; \
		done

post-install-IDE-on:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/etc/xdg/coq

.include <bsd.port.mk>
