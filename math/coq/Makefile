# New ports collection makefile for:	coq
# Date created:		2004-10-11
# Whom:			Rene Ladan <r.c.ladan@student.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	coq
PORTVERSION=	8.0p2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V8.0pl2/
DISTNAME=	coq-8.0pl2

MAINTAINER=	r.c.ladan@student.tue.nl
COMMENT=	Theorem prover based on lambda-C

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	--reals all
CONFIGURE_ARGS+=	--opt

ALL_TARGET=	world

PORTDOCS=	CHANGES COPYRIGHT CREDITS INSTALL LICENSE README

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	"OCaml bug prevents compilation"
.endif

.if exists(${LOCALBASE}/bin/lablgtk2)
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	IDE=""
.else
PLIST_SUB+=	IDE="@comment "
.endif

MAN1=	coq-interface.1 coq-tex.1 coq_makefile.1 coqc.1 coqdep.1 coqdoc.1 \
	coqmktop.1 coqtop.1 coqtop.byte.1 coqtop.opt.1 coqwc.1 gallina.1 \
	parser.1

post-install:
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
