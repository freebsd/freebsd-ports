# New ports collection makefile for:	coq
# Date created:		2004-10-11
# Whom:			Rene Ladan <r.c.ladan@student.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	coq
PORTVERSION=	8.2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://coq.inria.fr/V${PORTVERSION:R}/files/ \
		ftp://ftp.stack.nl/pub/users/johans/coq/
DISTNAME=	${PORTNAME}-${COQVERSION}

MAINTAINER=	johans@stack.nl
COMMENT=	Theorem prover based on lambda-C

BUILD_DEPENDS=	camlp5:${PORTSDIR}/devel/ocaml-camlp5

USE_OCAML=	yes
USE_GMAKE=	yes
ALL_TARGET=	world
WITH_IDE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	--reals all
CONFIGURE_ARGS+=	--opt

COQVERSION=	${PORTVERSION:R}-${PORTVERSION:E}
PORTDOCS=	CHANGES COPYRIGHT CREDITS INSTALL LICENSE README

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	OCaml bug prevents compilation
.endif

MAN1=	coq-interface.1 coq-tex.1 coq_makefile.1 coqc.1 coqdep.1 coqdoc.1 \
	coqmktop.1 coqtop.1 coqtop.byte.1 coqtop.opt.1 coqwc.1 gallina.1 \
	coq-parser.1

.if defined(WITH_IDE) || exists(${LOCALBASE}/bin/lablgtk2)
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	IDE=""
MAN1+=		coqide.1
.else
PLIST_SUB+=	IDE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/FreeBSD.*\.byte/s/^/#/' \
		-e '/^MAKE=/d' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
