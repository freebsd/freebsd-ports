# Created by: Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$

PORTNAME=	coq
PORTVERSION=	8.4.2
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	http://coq.inria.fr/distrib/V${COQVERSION}/files/ \
		ftp://ftp.stack.nl/pub/users/johans/coq/
DISTNAME=	${PORTNAME}-${COQVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Theorem prover based on lambda-C

BUILD_DEPENDS=	camlp5:${PORTSDIR}/devel/ocaml-camlp5 \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

COQVERSION=	${PORTVERSION:R}pl${PORTVERSION:E}
USE_OCAML=	yes
USE_GMAKE=	yes
ALL_TARGET=	world

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}
CONFIGURE_ARGS+=--mandir ${PREFIX}/man
CONFIGURE_ARGS+=--emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=--opt

OPTIONS_DEFINE=	IDE
OPTIONS_DEFAULT=IDE
IDE_DESC=	Include desktop environment (coqide)

MAN1=	coq-tex.1 coq_makefile.1 coqc.1 coqchk.1 coqdep.1 coqdoc.1 \
	coqmktop.1 coqtop.1 coqtop.byte.1 coqtop.opt.1 coqwc.1 gallina.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build dvipsk:build
BUILD_DEPENDS+=	hevea:${PORTSDIR}/textproc/hevea \
		${LOCALBASE}/share/texmf/tex/latex/ucs/utf8x.def:${PORTSDIR}/print/latex-ucs
PORTDOCS=	*
.else
CONFIGURE_ARGS+=--with-doc none
.endif

.if ${PORT_OPTIONS:MIDE}
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	IDE=""
MAN1+=		coqide.1
.else
PLIST_SUB+=	IDE="@comment "
CONFIGURE_ARGS+=--coqide no
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

post-patch:
	@${REINPLACE_CMD} -e '/FreeBSD.*\.byte/s/^/#/' \
		-e '1s:/bin/bash:/bin/sh:' \
		-e '/^MAKE=/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's:/bin/bash:/bin/sh:' \
		${WRKSRC}/Makefile* ${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e '/show_latex_mes/s/)$$/; true)/' ${WRKSRC}/Makefile.doc

.include <bsd.port.post.mk>
