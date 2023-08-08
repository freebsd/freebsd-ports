PORTNAME=	coq
PORTVERSION=	8.6
PORTREVISION=	18
PORTEPOCH=	3
CATEGORIES=	math
MASTER_SITES=	http://coq.inria.fr/distrib/V${PORTVERSION}/files/ \
		ftp://ftp.stack.nl/pub/users/johans/coq/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Theorem prover based on lambda-C
WWW=		https://coq.inria.fr/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fails to compile: Fatal error: exception Invalid_argument("index out of bounds")
BROKEN_armv7=	fails to compile: Fatal error: exception Invalid_argument("index out of bounds")

BUILD_DEPENDS=	camlp5:devel/ocaml-camlp5 \
		ocamlfind:devel/ocaml-findlib \
		${LOCALBASE}/${OCAML_SITELIBDIR}/num/META:math/ocaml-num
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/stublibs/dllnums.so:math/ocaml-num

USES=		emacs gettext-runtime gmake gnome
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtksourceview2 pango
USE_LDCONFIG=	${PREFIX}/lib/coq
USE_OCAML=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-mandir ${PREFIX}/man \
		-emacslib ${PREFIX}/share/emacs/site-lisp/coq \
		-usecamlp5 \
		-byteonly
MAKE_ENV=	VERBOSE=1 USERFLAGS=-unsafe-string
ALL_TARGET=	world

CONFLICTS_INSTALL=	coq coq-emacs_* # bin/coq-tex bin/coq_makefile bin/coqc bin/coqchk bin/coqdep bin/coqdoc bin/coqide bin/coqmktop bin/coqtop bin/coqtop.byte bin/coqwc bin/coqworkmgr bin/gallina

OPTIONS_DEFINE=		DOCS IDE
OPTIONS_DEFAULT=	IDE
OPTIONS_SUB=		yes
IDE_DESC=		Include desktop environment (coqide)
IDE_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_CONFIGURE_OFF=	-coqide no
DOCS_USES=		tex
DOCS_USE=		TEX=latex:build,dvipsk:build
DOCS_BUILD_DEPENDS=	hevea:textproc/hevea
DOCS_CONFIGURE_OFF=	-with-doc no

STRIP_FILES=		lib/coq/dllcoqrun.so

# Workaround bsd.ocaml.mk to fix packaging
add-plist-post:
	@${DO_NADA}

post-patch:
	@${REINPLACE_CMD} -e '/show_latex_mes/s/)$$/; true)/' \
		${WRKSRC}/Makefile.doc
# Allow passing USERFLAGS down to inner make(1) via environment
	@${REINPLACE_CMD} -e '/User compilation flag/,+1d' \
		${WRKSRC}/configure.ml

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${STRIP_FILES}

.include <bsd.port.mk>
