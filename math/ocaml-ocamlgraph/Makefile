# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocamlgraph
PORTVERSION=	1.8.7
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://ocamlgraph.lri.fr/download/ \
		ftp://ftp.stack.nl/pub/users/johans/ocamlgraph/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graph manipulation library for OCaml

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
OCAML_LDLIBS=	${OCAML_LIBDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

ALL_TARGET=	all
INSTALL_TARGET=	install

MAKE_JOBS_UNSAFE=	yes
PORTSCOUT=	skipv:1.81

PLIST_SUB=	OCAMLGRAPHDIR="${OCAML_LDLIBS}"

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes
GUI_DESC=		Include GUI user programs: viewer and editor
GUI_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
GUI_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
GUI_CONFIGURE_OFF=	LABLGTK2=no

DOCS_ALL_TARGET=	doc

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/VIEWER_DIR. doc/d' ${WRKSRC}/Makefile.in

post-patch-GUI-off:
	# Override auto-detection
	@${REINPLACE_CMD} -Ee 's/(LABLGTK2)=yes/\1=no/' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/META ${STAGEDIR}${PREFIX}/${OCAML_LDLIBS}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
