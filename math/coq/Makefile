# $FreeBSD$

PORTNAME=	coq
PORTVERSION=	8.4.6
PORTEPOCH=	3
CATEGORIES=	math
MASTER_SITES=	http://coq.inria.fr/distrib/V${COQVERSION}/files/ \
		ftp://ftp.stack.nl/pub/users/johans/coq/
DISTNAME=	${PORTNAME}-${COQVERSION}

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
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_OCAML=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} \
		--mandir ${PREFIX}/man \
		--emacslib ${PREFIX}/share/emacs/site-lisp \
		--opt
ALL_TARGET=	world

BROKEN_powerpc=		does not link

STRIP_FILES= \
	lib/coq/dllcoqrun.so \
	lib/coq/plugins/cc/cc_plugin.cmxs \
	lib/coq/plugins/decl_mode/decl_mode_plugin.cmxs \
	lib/coq/plugins/extraction/extraction_plugin.cmxs \
	lib/coq/plugins/field/field_plugin.cmxs \
	lib/coq/plugins/firstorder/ground_plugin.cmxs \
	lib/coq/plugins/fourier/fourier_plugin.cmxs \
	lib/coq/plugins/funind/recdef_plugin.cmxs \
	lib/coq/plugins/micromega/micromega_plugin.cmxs \
	lib/coq/plugins/nsatz/nsatz_plugin.cmxs \
	lib/coq/plugins/omega/omega_plugin.cmxs \
	lib/coq/plugins/quote/quote_plugin.cmxs \
	lib/coq/plugins/ring/ring_plugin.cmxs \
	lib/coq/plugins/romega/romega_plugin.cmxs \
	lib/coq/plugins/rtauto/rtauto_plugin.cmxs \
	lib/coq/plugins/setoid_ring/newring_plugin.cmxs \
	lib/coq/plugins/subtac/subtac_plugin.cmxs \
	lib/coq/plugins/syntax/ascii_syntax_plugin.cmxs \
	lib/coq/plugins/syntax/nat_syntax_plugin.cmxs \
	lib/coq/plugins/syntax/numbers_syntax_plugin.cmxs \
	lib/coq/plugins/syntax/r_syntax_plugin.cmxs \
	lib/coq/plugins/syntax/string_syntax_plugin.cmxs \
	lib/coq/plugins/syntax/z_syntax_plugin.cmxs \
	lib/coq/plugins/xml/xml_plugin.cmxs

OPTIONS_DEFINE=		DOCS IDE
OPTIONS_DEFAULT=	IDE
OPTIONS_SUB=		yes
IDE_DESC=		Include desktop environment (coqide)
IDE_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
IDE_CONFIGURE_OFF=	--coqide no
DOCS_USE=		TEX=latex:build,dvipsk:build,texmf:build
DOCS_BUILD_DEPENDS=	hevea:textproc/hevea
DOCS_CONFIGURE_OFF=	--with-doc none
PORTDOCS=		*

# Workaround bsd.ocaml.mk to fix packaging
add-plist-post:
	@${DO_NADA}

post-patch:
	${REINPLACE_CMD} -e '/FreeBSD.*\.byte/s/^/#/' \
	    -e '/^MAKE=/d' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/^#COQINSTALLPREFIX/{s/^#//;s|$$|$${DESTDIR}|;}' \
	    ${WRKSRC}/Makefile.build
	${REINPLACE_CMD} -e '/show_latex_mes/s/)$$/; true)/' \
	    ${WRKSRC}/Makefile.doc

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${STRIP_FILES}

.include <bsd.port.mk>
