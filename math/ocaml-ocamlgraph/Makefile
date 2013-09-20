# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocamlgraph
PORTVERSION=	1.8.3
CATEGORIES=	math
MASTER_SITES=	http://ocamlgraph.lri.fr/download/ \
		ftp://ftp.stack.nl/pub/users/johans/ocamlgraph/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Graph manipulation library for OCaml

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=GUI
GUI_DESC=	Include GUI user programs: viewer and editor

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB+=	OCAMLGRAPHDIR="${OCAML_LIBDIR}/${PORTNAME}"

ALL_TARGET=	all
INSTALL_TARGET=	install install-findlib

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	skipv:1.81

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	LABLGTK2=no
PLIST_SUB+=		GUI="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	doc
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/VIEWER_DIR. doc/d' ${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MGUI)
	# Override auto-detection
	@${REINPLACE_CMD} -Ee 's/(LABLGTK2)=yes/\1=no/' ${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} * ${DOCSDIR}
.endif

.include <bsd.port.mk>
