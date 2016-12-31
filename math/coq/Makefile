# $FreeBSD$

PORTNAME=	coq
PORTVERSION=	8.5
CATEGORIES=	math
MASTER_SITES=	http://coq.inria.fr/distrib/V${PORTVERSION}/files/ \
		ftp://ftp.stack.nl/pub/users/johans/coq/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Theorem prover based on lambda-C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	camlp5:devel/ocaml-camlp5 \
		ocamlfind:devel/ocaml-findlib
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

COQVERSION=	${PORTVERSION:R}pl${PORTVERSION:E}
USES=		gmake gettext-runtime
USE_EMACS=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtksourceview2 pango
USE_LDCONFIG=	${PREFIX}/lib/coq
USE_OCAML=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-mandir ${PREFIX}/man \
		-emacslib ${PREFIX}/share/emacs/site-lisp/coq \
		-usecamlp5 \
		-byteonly \
		-makecmd ${MAKE_CMD}
MAKE_ENV=	VERBOSE=1
ALL_TARGET=	world

BROKEN_powerpc=		does not link

OPTIONS_DEFINE=		DOCS IDE
OPTIONS_DEFAULT=	IDE
OPTIONS_SUB=		yes
IDE_DESC=		Include desktop environment (coqide)
IDE_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_CONFIGURE_OFF=	-coqide no
DOCS_USE=		TEX=latex:build,dvipsk:build,texmf:build
DOCS_BUILD_DEPENDS=	hevea:textproc/hevea
DOCS_CONFIGURE_OFF=	-with-doc no

STRIP_FILES=		lib/coq/dllcoqrun.so

# Workaround bsd.ocaml.mk to fix packaging
add-plist-post:
	@${DO_NADA}

post-patch:
	${REINPLACE_CMD} -e '/show_latex_mes/s/)$$/; true)/' \
	    ${WRKSRC}/Makefile.doc

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${STRIP_FILES}

.include <bsd.port.mk>
